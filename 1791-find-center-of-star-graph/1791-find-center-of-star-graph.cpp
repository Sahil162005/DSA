class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        int n=edges.size();
        for(auto it:edges){
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        int star=0;
        for(auto it:mpp){
            if(it.second==n){
                star=it.first;
                break;
            }
        }
        return star;
    }
};