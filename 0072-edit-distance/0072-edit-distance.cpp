class Solution {
public:
    int fn(string word1, string word2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1==0){
            return ind2;
        }
        if(ind2==0){
            return ind1;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int match=1e9;
        if(word1[ind1-1]==word2[ind2-1]){
            match=0+fn(word1,word2,ind1-1,ind2-1,dp);
        }
        int rep=1+fn(word1,word2,ind1-1,ind2-1,dp);
        int del=1+fn(word1,word2,ind1-1,ind2,dp);
        int ins=1+fn(word1,word2,ind1,ind2-1,dp);
        int notmatch=min({rep,del,ins});
        return dp[ind1][ind2]=min(match,notmatch);
    } 
    // int minDistance(string word1, string word2) {
    //     int n=word1.size();
    //     int m=word2.size();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return fn(word1,word2,n,m,dp);

    // }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int match=1e9;
                if(word1[i-1]==word2[j-1]){
                    match=dp[i-1][j-1];
                }
                int notmatch=min({1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});
                dp[i][j]=min(match,notmatch);
            }
        }
        return dp[n][m];
        

    }
};