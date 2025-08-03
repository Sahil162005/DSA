class Solution {
public:
//     bool fn(vector<int>& arr, int sum,int index,vector<vector<int>>&dp){
//     if(sum==0){
//           return true;
//       }
//     if (sum < 0) return false;
//       if (index == 0) return arr[0] == sum;
//       if(dp[index][sum]!=-1) return dp[index][sum];
//       bool skip=fn(arr,sum,index-1,dp);
//       bool take=false;
//       if(arr[index]<=sum){
//           take=fn(arr,sum-arr[index],index-1,dp);
//       }
//       return dp[index][sum]= skip||take;
//   }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=sum/2;j++){
                bool skip=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||skip;
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};