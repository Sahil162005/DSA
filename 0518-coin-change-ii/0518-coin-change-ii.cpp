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
        if (coins.empty()) return 0;
        vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<n;i++){
        dp[i][0]=1;
        }
        for (int j = 0; j <= amount; j++) {
       if (j % coins[0] == 0) dp[0][j] = 1;
          }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                unsigned long long nottake=dp[i-1][j];
        unsigned long long take=0;
        if(coins[i]<=amount){
            if(coins[i]<=j){
             take=dp[i][j-coins[i]];
            }
        }
       dp[i][j]=(take+nottake);
            }
        }
        return dp[n-1][amount];
        
    }
};