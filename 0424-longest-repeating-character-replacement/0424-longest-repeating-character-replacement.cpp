class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        unordered_map<int,int>mpp;
        int maxlen=0;
        int maxfreq=0;
        int n=s.size();
        int changes=0;
        while(r<n){
            mpp[s[r]-'A']++;
            if(mpp[s[r]-'A']>maxfreq){
                maxfreq=mpp[s[r]-'A'];
            }
            if(changes>k){
                mpp[s[l]-'A']--;
                int maxi=0;
                for(auto it:mpp){
                    maxi=max(maxi,it.second);
                }
                maxfreq=maxi;
                l++;
            }
            int len=r-l+1;
            changes=len-maxfreq;
            if(changes<=k){
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
        
    }
};