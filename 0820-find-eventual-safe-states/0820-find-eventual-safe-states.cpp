class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
         vector<int>indegree(n,0);
       vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
        for(auto it: graph[i]){
            adj[it].push_back(i);
        }
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
       sort(topo.begin(),topo.end());
       
       return topo;
    }
};