class Solution {
public:
    int fn(vector<int>&prices,int ind, vector<vector<vector<int>>>&dp,int canbuy,int transactions){
        if(ind==prices.size()){
            return 0;
        }
        if(transactions==0){
            return 0;
        }
        if(dp[ind][canbuy][transactions]!=-1)return dp[ind][canbuy][transactions];
        int profit = 0;
        
        if(canbuy == 1 ) {
            int buy = -prices[ind] + fn(prices, ind + 1, dp, 0,transactions); 
            int skip = fn(prices, ind + 1, dp, 1,transactions);               
            profit = max(buy, skip);
        }
        else{
            int sell = prices[ind] + fn(prices, ind + 1, dp, 1,transactions-1); 
            int skip = fn(prices, ind + 1, dp, 0,transactions); 
            profit = max(sell, skip);
        }
         return dp[ind][canbuy][transactions] = profit;
    }
    // int maxProfit(vector<int>& prices) {
    //       int n=prices.size();
    //        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //        return fn(prices,0,dp,1,2);
    // }
        int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int take = 0, not_take = 0;
                    if (buy) {
                        take = -prices[idx] + dp[idx + 1][0][cap];
                        not_take = dp[idx + 1][1][cap];
                    } else {
                        take = prices[idx] + dp[idx + 1][1][cap - 1];
                        not_take = dp[idx + 1][0][cap];
                    }

                    dp[idx][buy][cap] = max(take, not_take);
                }
            }
        }
        return dp[0][1][2];
    }
    
};