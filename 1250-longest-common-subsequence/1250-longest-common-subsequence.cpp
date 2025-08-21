class Solution {
public:
    int fn(string text1, string text2,int index1,int index2,vector<vector<int>>&dp){
        if(index1==0 || index2==0){
            return 0;
        }
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        int match=0;
        if(text1[index1-1]==text2[index2-1]){
            match=1+fn(text1,text2,index1-1,index2-1,dp);
        }
        int notmatch=max(fn(text1,text2,index1,index2-1,dp),fn(text1,text2,index1-1,index2,dp));
        
        return dp[index1][index2]=max(match,notmatch);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int n1=text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(n1+1,-1));
        // return fn(text1,text2,n,n1,dp);
        vector<vector<int>>dp(n+1,vector<int>(n1+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n1;j++){
                int match=0;
                if(text1[i-1]==text2[j-1]){
                    match=1+dp[i-1][j-1];
                }
                int notmatch=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(match,notmatch);
            }
        }
        return dp[n][n1];
    }
};