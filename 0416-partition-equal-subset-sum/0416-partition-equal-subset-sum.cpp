class Solution {
public:
   bool fn(int index,int sum,vector<int>&nums,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(index==0) return (nums[0]==sum);
    if(dp[index][sum]!=-1) return dp[index][sum];
    bool nt=fn(index-1,sum,nums,dp);
    bool t=false;
    if(nums[index]<=sum){
        t=fn(index-1,sum-nums[index],nums,dp);
    }
    dp[index][sum]= t||nt;
    return dp[index][sum];
   }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 !=0) return false;
        int sum1=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum1+1,-1));
        return fn(n-1,sum1,nums,dp);
    }
};