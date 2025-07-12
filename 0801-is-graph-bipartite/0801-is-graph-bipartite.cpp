class Solution {
public:
    bool dfs(int node,int col,vector<int>&vis,vector<vector<int>>& graph){
        vis[node]=col;
        for(auto it : graph[node]){
            if(vis[it]==-1){
                if(dfs(it,!col,vis,graph)==false) return false;
            }
            else if(vis[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>vis(m,-1);
        for(int i=0;i<m;i++){
            if(vis[i]==-1){
           if(dfs(i,0,vis,graph)==false)  return false;
        }
        }
        return true;
    }
};