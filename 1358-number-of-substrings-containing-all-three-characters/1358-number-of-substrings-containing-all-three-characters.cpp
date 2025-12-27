class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        // unordered_map<char,int>mpp;
        int r=0,l=0;
        int cnt=0;
        int mpp[3]={0,0,0};
        while(r<n){
            mpp[s[r]-'a']++;
            while(mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0){
                cnt+=n-r;
                mpp[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};