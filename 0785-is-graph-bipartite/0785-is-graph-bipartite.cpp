class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>&vis,int node){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curnode=q.front();
            q.pop();
            for(int nodes:graph[curnode]){
               if(vis[nodes]==vis[curnode]){
                return false;
               }
               else if(vis[nodes]==3){
                vis[nodes]=!vis[curnode];
                q.push(nodes);
               }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,3);
        for(int u=0;u<n;u++){
            if(vis[u]==3){
                vis[u]=1;
              if( bfs(graph,vis,u)==false){
                return false;
              }
            }
        }
        return true;
    }
};