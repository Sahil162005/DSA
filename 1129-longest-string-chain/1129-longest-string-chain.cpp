class Solution {
public:
    bool compare(string &s1,string&s2){
        if(s1.size()!=s2.size()+1) return false;
        int i=0;
        int j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j] && j<s2.size()){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
       if(i==s1.size() && j==s2.size())return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        if(n==1)return 1;
        vector<int>dp(n,1);
        sort(words.begin(), words.end(), [](const string& a, const string& b){
        return a.size() < b.size();
    });
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) &&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                }
            }
        }
        return maxi;
    }
};