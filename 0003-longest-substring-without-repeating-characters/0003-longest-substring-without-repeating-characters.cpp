class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        int l=0,r=0;
        unordered_map<char,int>mpp;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                if(mpp[s[r]]>=l){
                l=mpp[s[r]]+1;
                }
            }
            int len=r-l+1;
            mpp[s[r]]=r;
            maxlen=max(maxlen,len);
            r++;
            
        }
        return maxlen;
    }
};