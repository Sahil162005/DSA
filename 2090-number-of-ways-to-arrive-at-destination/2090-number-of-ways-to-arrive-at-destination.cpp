class Solution {
public:
    int a=1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long>dis(n,LLONG_MAX );
        vector<vector<pair<int,int>>>adj(n);
        dis[0]=0;
        for(auto it : roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> ways(n, 0);
       ways[0] = 1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long w=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if (w > dis[u]) continue;
            for(auto it :adj[u]){
               int node=it.first;
               long long weight = it.second;
               if(weight+w<dis[node]){
                dis[node]=weight+w;
                ways[node]=ways[u];
                pq.push({dis[node],node});
               }
               else if(dis[node]==weight+w){
                ways[node]=(ways[node]+ways[u])%a;
               }
            }
        }
        return ways[n-1];
        
    }
};