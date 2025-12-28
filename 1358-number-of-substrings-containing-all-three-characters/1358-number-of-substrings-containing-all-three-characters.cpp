class Solution {
public:
int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        int mpp[3]={-1,-1,-1};
        for(int i=0;i<n;i++){
            mpp[s[i]-'a']=i;
            if(mpp[0] > -1 && mpp[1] > -1 && mpp[2] > -1){
                cnt+=(1+ min(mpp[0],min(mpp[1],mpp[2])));
                
            }
        }
        return cnt;
    }
    // int numberOfSubstrings(string s) {
    //     int n=s.size();
    //     int r=0,l=0;
    //     int cnt=0;
    //     int mpp[3]={0,0,0};
    //     while(r<n){
    //         mpp[s[r]-'a']++;
    //         while(mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0){
    //             cnt+=n-r;
    //             mpp[s[l]-'a']--;
    //             l++;
    //         }
    //         r++;
    //     }
    //     return cnt;
    // }
};