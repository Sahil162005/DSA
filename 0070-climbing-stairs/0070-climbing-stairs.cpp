class Solution {
public:
    int fn(int n, vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int one= fn(n-1,dp);
        int two= fn(n-2,dp);
        int ans= one+two;
        return dp[n]=ans;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};