class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        unordered_map<int,int>mpp;
        int maxlen=0;
        int maxfreq=0;
        int n=s.size();
        while(r<n){
            mpp[s[r]-'A']++;
            if(mpp[s[r]-'A']>maxfreq){
                maxfreq=mpp[s[r]-'A'];
            }
            if((r-l+1-maxfreq)>k){
                mpp[s[l]-'A']--;
                // int maxi=0;
                // for(auto it:mpp){
                //     maxi=max(maxi,it.second);
                // }
                // maxfreq=maxi;
                l++;
            }
            if((r-l+1-maxfreq)<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
        
    }
};