class Solution {
public:
   int fn(int ind,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(ind==0){
            if(amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake=fn(ind-1,amount,coins,dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+fn(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=fn(n-1,amount,coins,dp);
        if(res==1e9) return -1;
        return res;
        
    }
};