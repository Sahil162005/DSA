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
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int res=fn(n-1,amount,coins,dp);
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
    for(int j=0;j<=amount;j++){
        if(j%coins[0]==0) dp[0][j]=j/coins[0];
        else dp[0][j]=1e9;
    }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                 int nottake=dp[i-1][j];
                 int take=1e9;
                  if(coins[i]<=j){
                  take=1+dp[i][j-coins[i]];
                   }
                dp[i][j]=min(take,nottake);
            }
        }
        int res=dp[n-1][amount];

        if(res==1e9) return -1;
        return res;
        
    }
};