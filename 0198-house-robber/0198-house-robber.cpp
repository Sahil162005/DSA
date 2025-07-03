class Solution {
public:
    int solve(vector<int>& dp,vector<int>& nums,int n){
         if (n < 0) return 0;
        if(dp[n]!=-1) return dp[n];

        dp[n]=max(solve(dp,nums,n-1),solve(dp,nums,n-2)+nums[n]);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        // tabulation
        // int n=nums.size();
        // if(n==1){
        //     return nums[0];
        // }
        // vector<int>dp(n+1,0);
        // dp[0]=nums[0];
        // dp[1] = max(nums[0], nums[1]);;
        // for(int i=2;i<n;i++){
        //     dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

        // }
        // return dp[n-1];

        //optimized S.C
        // int n=nums.size();
        // if(n==1){
        //     return nums[0];
        // }
        // int prev1=nums[0];
        // int prev2=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     int curr =max(prev2,prev1+nums[i]);
        //     prev1=prev2;
        //     prev2=curr;
        // }
        // return prev2;

        //Memoization
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n+1,-1);
        return solve(dp,nums,n-1);
    }
};