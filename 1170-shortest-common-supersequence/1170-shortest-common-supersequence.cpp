class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int match=0;
                if(text1[i-1]==text2[j-1]){
                    match=1+dp[i-1][j-1];
                }
                int notmatch=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(match,notmatch);
            }
        }
        int i=n,j=m;
		string ans="";
		while(i>0 && j>0){
			if(text1[i-1]==text2[j-1]){
				ans+=text1[i-1];
				i=i-1;
				j=j-1;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					ans+=text1[i-1];
                    i--;
				}
				else{
                    ans+=text2[j-1];
					j--;
				}
			}
		}
        while(i>0){
            ans+=text1[i-1];
            i--;
        }
         while(j>0){
            ans+=text2[j-1];
            j--;
        }
		reverse(ans.begin(),ans.end());
		return ans;
    }
};