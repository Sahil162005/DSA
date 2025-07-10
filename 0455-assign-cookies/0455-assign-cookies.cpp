class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0;
        int j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }
            else if(g[i]>s[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return cnt;
        
        
    }
};