class Solution {
public:
    int fn(string s,string t,int index1,int index2,vector<vector<int>>&dp){
        if (index2 < 0) return 1;
        if (index1 < 0) return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        int take=0;
        if(s[index1]==t[index2]){
        take= fn(s,t,index1-1,index2-1,dp);
        }
        int nottake=fn(s,t,index1-1,index2,dp);
        return dp[index1][index2]=take+nottake;
    }
    // int numDistinct(string s, string t) {
    //     int n=s.size();
    //     int m=t.size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return fn(s,t,n-1,m-1,dp);
    // }
    long long numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n=s.size();
        int m=t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                long long take=0;
                if(s[i-1]==t[j-1]){
                    take=dp[i-1][j-1];
                }
                long long nottake=dp[i-1][j];
                dp[i][j]=(take+nottake) % MOD;;
            }
        }
        return dp[n][m];
    }
};