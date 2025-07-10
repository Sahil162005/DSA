class Solution {
public:
   int fn(int ind,int target,vector<int>&nums,vector<vector<int>>&dp,int sum){
    if(target+sum>sum || target+sum <-sum) return 0;
    if(target==0) return 1;
    if(ind==0){
        if(target==nums[ind]) return 1;
        return 0;
    }
    if(dp[ind][target+sum]!=-1)return dp[ind][target+sum];
    int num=nums[ind];
    int plus=fn(ind-1,target+(-num),nums,dp,sum);
    int neg=fn(ind-1,target+num,nums,dp,sum);
    return dp[ind][target+sum]=plus+neg;
   }
    int findTargetSumWays(vector<int>& arr, int d) {
         int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(abs(d)>sum) return 0;
        if(sum<d || (sum-d)%2!=0) return 0;
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(arr[0]<=sum && arr[0]==0){
            dp[0][arr[0]]=2;
        }
        else{
            dp[0][arr[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int nt=dp[i-1][j];
                int t=0;
                if(arr[i]<=j){
                    t=dp[i-1][j-arr[i]];
                }
                dp[i][j]=t+nt;
            }
        }
        int s2=(sum-d)/2;
        return dp[n-1][s2];
    }
};