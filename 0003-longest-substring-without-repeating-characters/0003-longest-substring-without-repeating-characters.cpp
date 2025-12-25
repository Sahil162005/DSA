class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>hash;
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                int len=j-i+1;
                maxlen=max(len,maxlen);
                hash[s[j]]=1;
            }
        }
        return maxlen;
    }
};