class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>&vis,int node){
        vis[node]= 1;
        for(auto it:rooms[node]){
            if(vis[it]!=1){
                dfs(rooms,vis,it);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        dfs(rooms,vis,0);
        bool ans = true;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                ans=false;
                break;
            }
        }
        return ans;
    }
};