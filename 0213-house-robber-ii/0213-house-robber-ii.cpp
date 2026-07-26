class Solution {
public:
   int fn(vector<int>&nums,int i,int end,vector<int>&dp){
    if(i==end){
        return nums[end];
    }
    if(i > end){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans = nums[i] + fn(nums,i+2,end,dp);
    int skip = fn(nums,i+1,end,dp);
    return dp[i] = max(ans,skip);
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);

        int start1= fn(nums,0,n-2,dp1);
        int start2 = fn(nums,1,n-1,dp2);
        return max(start1,start2);
        
    }
};