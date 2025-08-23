class Solution {
public:
    bool fn(string s,string p,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind2==0 && ind1==0){
            return true;
        }
        if(ind1==0 && ind2>=0){
            for(int i=1;i<=ind2;i++){
                if(p[i-1]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(ind2==0 && ind1>0){
            return false;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        bool match=false;
        bool starmatch=false;
        if(s[ind1-1]==p[ind2-1] || p[ind2-1]=='?'){
            match=fn(s,p,ind1-1,ind2-1,dp); 
        }
        if(p[ind2-1]=='*'){
            starmatch=fn(s,p,ind1-1,ind2,dp) || fn(s,p,ind1,ind2-1,dp); 
        }
        return dp[ind1][ind2]=match||starmatch;
    }
    // bool isMatch(string s, string p) {
    //    int n=s.size();
    //    int m=p.size();
    //    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //    return fn(s,p,n,m,dp); 
    // }
    bool isMatch(string s, string p) {
       int n=s.size();
       int m=p.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       dp[0][0]=1;
       for(int i=1;i<=n;i++){
        dp[i][0]=false;
       }
       for(int j=1;j<=m;j++){
        dp[0][j] = dp[0][j-1] && (p[j-1] == '*');
       }

       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool match=false;
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
            match=dp[i-1][j-1];}
            bool starmatch=false;
            if(p[j-1]=='*'){
            starmatch=dp[i-1][j]||dp[i][j-1];
            }
            dp[i][j]=match||starmatch;
        }
        }
       return dp[n][m]; 
    }
};