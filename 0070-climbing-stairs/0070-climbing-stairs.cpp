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
        //int prev1=1;
        //int prev2=1;
        //for(int i=2;i<=n;i++){
          //  int curr=prev1+prev2;
           // prev2=prev1;
           // prev1=curr;
       // }
        //return prev1;
        //Memoization 
        int sol=solve(dp,n);
        return sol;
    }
    int solve(vector<int>&dp,int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=solve(dp,n-1)+solve(dp,n-2);
    }
};