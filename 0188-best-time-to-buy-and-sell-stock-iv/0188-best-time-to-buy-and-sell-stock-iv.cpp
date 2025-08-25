class Solution {
public:
    int fn(vector<int>&prices,int ind, vector<vector<vector<int>>>&dp,int canbuy,int transactions,int k){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][canbuy][transactions]!=-1)return dp[ind][canbuy][transactions];
        int profit = 0;
        
        if(canbuy == 1 && transactions<k) {
            int buy = -prices[ind] + fn(prices, ind + 1, dp, 0,transactions,k); 
            int skip = fn(prices, ind + 1, dp, 1,transactions,k);               
            profit = max(buy, skip);
        }
        else if(transactions<k) {
            int sell = prices[ind] + fn(prices, ind + 1, dp, 1,transactions+1,k); 
            int skip = fn(prices, ind + 1, dp, 0,transactions,k); 
            profit = max(sell, skip);
        }
         return dp[ind][canbuy][transactions] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
           vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
           return fn(prices,0,dp,1,0,k);
    }
};