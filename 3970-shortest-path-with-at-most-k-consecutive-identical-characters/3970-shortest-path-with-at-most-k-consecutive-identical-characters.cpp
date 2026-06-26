class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,1}});
        dist[0][1]=0;
        while(!pq.empty()){
            int node = pq.top().second.first;
            int cost = pq.top().first;
            int cnt = pq.top().second.second;
            pq.pop();
            if(cost > dist[node][cnt]) continue;
            for(auto it : adj[node]){
                int currcost = cost + it.second;
                int currcnt = cnt+1;
                if(labels[node] != labels[it.first]){
                    currcnt = 1;
                }
                if(currcnt <=k){
                if(currcost < dist[it.first][currcnt]){
                    dist[it.first][currcnt] = currcost;
                    pq.push({currcost,{it.first,currcnt}});
                }
                }
            }
        }
        int mini = INT_MAX;
        for(int i=1;i<=k ; i++){
            mini = min(mini,dist[n-1][i]);
        }
        if(mini ==INT_MAX){
            return -1;
        }
        return mini;
    }
};