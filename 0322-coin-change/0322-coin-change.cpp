class Solution {
public:
    int fn(int amount, vector<int>& coins,vector<vector<int>>&dp,int i){
        if(amount==0){
            return 0;
        }
        if(i==0){
            if(amount%coins[i]==0){
                return amount/coins[i];
            }
            return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int use = 1e9;
        if(amount>=coins[i]){
            use= 1+fn(amount-coins[i],coins,dp,i);
        }
        int notuse = fn(amount,coins,dp,i-1);
        int ans= min(notuse,use);
        return dp[i][amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
         int ans= fn(amount,coins,dp,n-1);
         if(ans>=1e8){
            return -1;
         }
         return ans;
    }
};