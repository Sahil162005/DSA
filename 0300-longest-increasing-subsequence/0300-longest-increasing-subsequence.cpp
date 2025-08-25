class Solution {
public:
    int fn(vector<int>&nums,int ind,int prev,vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int pick=0;
        if(prev==-1||nums[ind]>nums[prev]){
            pick=1+fn(nums,ind+1,ind,dp);
        }
        int notpick=0+fn(nums,ind+1,prev,dp);
        return dp[ind][prev+1]=max(pick,notpick);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fn(nums,0,-1,dp);
    }
};