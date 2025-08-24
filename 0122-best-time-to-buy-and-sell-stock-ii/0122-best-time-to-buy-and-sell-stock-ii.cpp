class Solution {
public:
    int fn(vector<int>&prices,int ind,vector<vector<int>>&dp,int canbuy){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        int profit = 0;
        
        if(canbuy == 1) {
            int buy = -prices[ind] + fn(prices, ind + 1, dp, 0); 
            int skip = fn(prices, ind + 1, dp, 1);               
            profit = max(buy, skip);
        }
        else {
            int sell = prices[ind] + fn(prices, ind + 1, dp, 1); 
            int skip = fn(prices, ind + 1, dp, 0); 
            profit = max(sell, skip);
        }
         return dp[ind][canbuy] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(prices,0,dp,1);
        
    }
};