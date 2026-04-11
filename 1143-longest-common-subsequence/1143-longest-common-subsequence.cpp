class Solution {
public:
    int fn(string &text1, string &text2,vector<vector<int>>&dp,int i,int j){
        if(j==0||i==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int match=0;
        int notmatch=0;
        if(text1[i-1]==text2[j-1]){
            match=1+fn(text1,text2,dp,i-1,j-1);
        }
        else{
            match=max(fn(text1,text2,dp,i-1,j),fn(text1,text2,dp,i,j-1));
        }

       return dp[i][j]=max(match,notmatch);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,(vector<int>(m+1,-1)));
        return fn(text1,text2,dp,n,m);
    }
};