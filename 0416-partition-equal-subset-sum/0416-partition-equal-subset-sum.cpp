class Solution {
public:
   bool fn(int index,int sum,int totalsum,vector<int>&nums,vector<vector<int>>&dp){
    if(sum==totalsum-sum) return true;
    if(index==0) return false;
    if(dp[index][sum]!=-1) return dp[index][sum];
    bool nt=fn(index-1,sum,totalsum,nums,dp);
    bool t=false;
    if(nums[index]<=totalsum){
        t=fn(index-1,sum+nums[index],totalsum,nums,dp);
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
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fn(n-1,0,sum,nums,dp);
    }
};