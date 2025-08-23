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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fn(word1,word2,n,m,dp);


    }
};