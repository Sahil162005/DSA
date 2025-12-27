class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int r=0,l=0;
        int cnt=0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0){
                cnt+=n-r;
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};