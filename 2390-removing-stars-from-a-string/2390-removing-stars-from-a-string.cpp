class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int star = -1;
        string res = "";
       for(int i=0;i<n;i++){
        if(s[i]!='*'){
            res+=s[i];
        }
        if(s[i]=='*' && !res.empty()){
            res.pop_back();
        }
       }
       return res;
    }
};