class Solution {
public:
 // Tabulation Solution
    // int solve(vector<int>& nums,int start,int end){
    //     int len = end - start + 1;
    //     if (len == 1) return nums[start];
    //      vector<int> dp(len);
    //     dp[0]=nums[start];
    //     dp[1]=max(nums[start],nums[start+1]);
    //     for(int i=2;i<len;i++){
    //         dp[i] = max(dp[i-1], dp[i-2] + nums[start+i]);

    //     }
    //     return dp[len-1];
    // }
    int solve(vector<int>& nums,int start,int end){
         int prev1=nums[start];
         if(end-start+1==1){
            return nums[start];
         }
        int prev2=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            int curr =max(prev2,prev1+nums[i]);
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};