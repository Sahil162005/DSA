class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,INT_MAX);
        queue<pair<pair<int,int>,int>>q;
        q.push({{src,0},-1});
        dis[src]=0;
        int cnt=0;
        vector<vector<pair<int,int>>>adj(n);
       for (auto it : flights) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        }
        int val=INT_MAX;
        while(!q.empty()){
            int node=q.front().first.first;
            int w=q.front().first.second;
            int stops=q.front().second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int u=it.first;
                int cost=it.second;
                 if(dis[u]>cost+w && stops<k){
                    dis[u]=cost+w;
                    q.push({{u,dis[u]},stops+1});
                }
            }


        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
        
    }
};