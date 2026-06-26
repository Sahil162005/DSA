class Solution {
public:
    int fn(vector<int>&nums , int ind,vector<int>&dp){
        if(ind >= nums.size()-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int count = 1e9;
        int jumps = nums[ind];
        for(int i = ind+1; i<=ind+jumps;i++){
            if(i <= nums.size()-1){
            count = min(1+fn(nums,i,dp),count) ;
            }
        }
        return dp[ind]=count;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return fn(nums,0,dp);
    }
};