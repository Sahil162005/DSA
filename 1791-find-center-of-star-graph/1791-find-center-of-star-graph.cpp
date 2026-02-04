class Solution {
public:
int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0]==edges[1][0] ||edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        return edges[0][1];
    }
    // int findCenter(vector<vector<int>>& edges) {
    //     unordered_map<int,int>mpp;
    //     int n=edges.size();
    //     for(auto it:edges){
    //         mpp[it[0]]++;
    //         mpp[it[1]]++;
    //     }
    //     int star=0;
    //     for(auto it:mpp){
    //         if(it.second==n){
    //             star=it.first;
    //             break;
    //         }
    //     }
    //     return star;
    // }
};