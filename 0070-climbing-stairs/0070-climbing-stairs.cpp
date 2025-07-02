class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        /// tabulation
        // dp[0]=1;
        // dp[1]=1;
       // for(int i=2;i<=n;i++){
         //   dp[i]=dp[i-1]+dp[i-2];
       // }
        //return dp[n];
        //
        // optimized S.C. Tabulation 
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};