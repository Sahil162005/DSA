class Solution {
public:
//    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&path, vector<int>&order){
//     vis[node]=1;
//     path[node]=1;
//     for(auto it : adj[node]){
//         if(vis[it]!=1){
//             if(dfs(it,adj,vis,path,order)==false) return false;
//         }
//             else if(path[it]==1)  return false;
        
//     }
//     path[node]=0;
//     order.push_back(node);
//     return true;

//    }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         if(prerequisites.size() == 0) {
//         vector<int> res;
//          for (int i = 0; i < numCourses; i++) res.push_back(i);
//            return res;
//             }
//         vector<int>order;
//         int n=numCourses;
//         vector<int>path(n,0);
//         vector<int>vis(n,0);
//         vector<vector<int>>adj(n);
//         for (auto &pre : prerequisites) {
//             int u = pre[0], v = pre[1];
//             adj[v].push_back(u);
//         }
//         for(int i=0;i<n;i++){
//             if(vis[i]!=1){
//            if( ! (dfs(i,adj,vis,path,order))) return {};
//             }
//         }
//         reverse(order.begin(), order.end());
//         return order;
//     }

 vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int>indegree(n,0);
       vector<vector<int>>adj(n);
       for(auto it: prerequisites){
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);
       }
       for(int i=0;i<n;i++){
        for(auto it:adj[i] ){
            indegree[it]++;
        }
       }
       queue<int>q;
       for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
       }
       vector<int>topo;
       while(!q.empty()){
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(auto it : adj[u]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
       }
       if(topo.size()==n) return topo;
       return {};
       
     }
};