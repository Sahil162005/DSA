class Solution {
public:
//    bool fn(vector<int>& nums,int i,vector<int>&dp){
//     if(i==nums.size()-1){
//         return true;
//     }
//     if(dp[i]!=-1){
//         return dp[i];
//     }
//     bool ans=false;
//     for(int j=1;j<=nums[i];j++){
//         bool curr=false;
//         if(i+j<nums.size()){
//             curr = fn(nums,i+j,dp);
//         }
//         ans= curr || ans;
//     }
//     return dp[i]=ans;
//    }
    // bool canJump(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n+1,-1);
    //     return fn(nums,0,dp);
    // }
     bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxind=0;
        for(int i=0;i<n;i++){
             if(i>maxind){
                return false;
            }
            if(i+nums[i]>maxind){
            maxind=nums[i]+i;
            }
            if(maxind>=n-1){
                break;
            }
        }
        return true;
    }
};