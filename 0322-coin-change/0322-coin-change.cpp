class Solution {
public:
   int fn(vector<int>& coins, int amount,vector<vector<int>>&dp,int index){
    if(amount==0){
        return 0;
    }
    if(index==0){
        if(amount%coins[0]==0){
            return amount/coins[0];
        }
        return 1e8;
    }
    if(dp[index][amount]!=-1)return dp[index][amount];
    int nottake=fn(coins,amount,dp,index-1);
    int take=1e8;
    if(coins[index]<=amount){
        take=1+fn(coins,amount-coins[index],dp,index);
    }
    return dp[index][amount]=min(take,nottake);
   }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res= fn(coins,amount,dp,coins.size()-1);
        if(res>=1e8)return -1;
        return res;  
    }
};