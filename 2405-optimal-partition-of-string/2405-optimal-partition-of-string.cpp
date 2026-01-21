class Solution {
public:
    int partitionString(string s) {
        int l=0,r=0;
        unordered_map<int,int>mpp;
        int n=s.size();
        int cnt=0;
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]]>1){
                cnt++;
                mpp.clear();
                mpp[s[r]] = 1;
            }
            r++;
        }
        return cnt+1;
        
    }
};