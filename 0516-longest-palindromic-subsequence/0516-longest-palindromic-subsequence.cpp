class Solution {
public:
    int fn(string s,int right,int left,vector<vector<int>>&dp){
        if (left > right) return 0;
        if(right==left){
            return 1;
        }
        if(dp[left][right]!=-1)return dp[left][right];
        if(s[right]==s[left]){
            return dp[left][right]=2+fn(s,right-1,left+1,dp);
        }
       return dp[left][right]=max(fn(s,right-1,left,dp),fn(s,right,left+1,dp));
    }
    // int longestPalindromeSubseq(string s) {
    //     int n=s.size();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
    //     return fn(s,n-1,0,dp);
    // }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];

    }
};