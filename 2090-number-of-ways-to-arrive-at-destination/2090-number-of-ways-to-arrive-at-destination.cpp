class Solution {
public:
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
                long long weight=it.second;
                if (dis[node] > w + weight) {
               dis[node] = w + weight;
                ways[node] = ways[u];
                pq.push({weight+w,node});
            } else if (dis[node] == w + weight) {
              ways[node] = (ways[node] + ways[u]) % 1000000007;
            }
            }
        }
        return ways[n-1];
        
    }
};