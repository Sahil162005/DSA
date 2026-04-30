class Solution {
public:
    int fn(vector<int>& nums,int ind,int last,vector<int>&dp){
        if(ind>last){
            return 0;
        }
        if(ind==last){
            return nums[ind];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take = nums[ind] + fn(nums,ind+2,last,dp);
        int nottake= fn(nums,ind+1,last,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(fn(nums,0,n-2,dp1),fn(nums,1,n-1,dp2));
    }
};