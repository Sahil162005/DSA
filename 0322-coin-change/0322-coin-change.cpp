class Solution {
public:
    int fn(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(ind==0){
            if (amount % coins[ind] == 0) return amount / coins[0];
            return 1e9; 
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nt=fn(ind-1,coins,amount,dp);
        int t=1e9;
        if(coins[ind]<=amount){
            t=1+fn(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(t,nt);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res= fn(coins.size()-1,coins,amount,dp);
        if(res==1e9) return -1;
        return res;
        
    }
};