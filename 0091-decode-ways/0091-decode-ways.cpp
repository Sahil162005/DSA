class Solution {
public:
    int fn(string s ,int i,vector<int>&dp){
        if(i>s.size()){
            return 0;
        }
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        char c = s[i];
        int res = 0;
        if(c == '0'){
            return 0;
        }
            int single = fn(s,i+1,dp);
            int dble =0;
            if(i+1<s.size()){
                int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(twoDigit<= 26){
                    dble = fn(s,i+2,dp);
                }
            }
        return dp[i] = single + dble;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        if(n==1){
            if(s[0]=='0'){
                return 0;
            }
            return 1;
        }
        return fn(s,0,dp);
    }
};