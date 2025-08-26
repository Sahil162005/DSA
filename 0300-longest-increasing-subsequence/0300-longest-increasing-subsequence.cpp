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
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return fn(nums,0,-1,dp);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     vector<int>pre(n+1,0);
    //     vector<int>curr(n+1,0);

    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev=ind-1;prev>=-1;prev--){
    //              int pick=0;
    //     if(prev==-1||nums[ind]>nums[prev]){
    //         pick=1+pre[ind+1];
    //     }
    //     int notpick=0+pre[prev+1];
    //     curr[prev+1]=max(pick,notpick);
    //         }
    //         pre=curr;
    //     }
    //     return pre[0];
    // }
     int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
               maxi=max(maxi,dp[i]);
            }
        }
        return maxi;
    }

};