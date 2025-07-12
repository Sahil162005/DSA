class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
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
       int cnt=0;
       while(!q.empty()){
        int u=q.front();
        q.pop();
        cnt++;
        for(auto it : adj[u]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
       }
       if(cnt==n) return true;
       return false;
    }
};