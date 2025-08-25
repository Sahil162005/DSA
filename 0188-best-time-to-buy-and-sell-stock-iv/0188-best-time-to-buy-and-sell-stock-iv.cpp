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
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
           vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
           return fn(prices,0,dp,1,k);
    }
};