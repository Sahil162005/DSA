class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        int cnt=t.size();
        int c=0;
        int l=0,r=0;
        int start=-1;
        int len=-1;
        int minilen=INT_MAX;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end()){
                mpp[s[r]]--;
                if (mpp[s[r]] >= 0) c++;
            }
                while(cnt==c){
                    if(r-l+1<minilen){
                        minilen=r-l+1;
                        start=l;
                    }
                    if(mpp.find(s[l])!=mpp.end()){
                        mpp[s[l]]++;
                        if(mpp[s[l]]>0){
                        c--;
                    }
                    }
                    l++;
                }
                r++;
            }
        if(minilen==INT_MAX){
            return "";
        }
        return s.substr(start,minilen);
    }
};