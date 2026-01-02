class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        int si=0,l=0,r=0,cnt=0;
        int minlen=INT_MAX;
        while(r<n){
            if(mpp[s[r]]>0)cnt++;
            mpp[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    si=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
            
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(si,minlen);
    }
};