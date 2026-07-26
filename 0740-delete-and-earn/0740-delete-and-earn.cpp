class Solution {
public:
    int fn(int i,vector<int>&arr,vector<int>&dp){
        if(i == arr.size()-1){
            return arr[i];
        }
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = 0;
        if(arr[i] != 0){
            take  = arr[i] + fn(i+2,arr,dp);
        }
        int nottake = fn(i+1,arr,dp);
        return dp[i] = max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        vector<int>arr(maxi+1,0);
        for(int i = 0;i<n;i++){
            arr[nums[i]]+=nums[i];
        }
        vector<int>dp(maxi+1,-1);
        return fn(0,arr,dp);
    }
};