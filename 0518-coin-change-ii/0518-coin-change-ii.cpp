class Solution {
public:
    int fn(int ind,int amount,vector<int>& nums,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==0){
            if(amount%nums[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake=fn(ind-1,amount,nums,dp);
        int take=0;
        if(nums[ind]<=amount){
            take=fn(ind,amount-nums[ind],nums,dp);
        }
        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=coins[i];
        }
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fn(n-1,amount,coins,dp);
    }
};