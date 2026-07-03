class Solution {
public:
    bool feasible(vector<vector<pair<int,int>>>& adj, vector<bool>& online,
                  long long k, int mid, int n) {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;    
            if (node == n - 1) return d <= k;  
            if (node != 0 && !online[node]) continue; 
            for (auto it : adj[node]) {
                int x = it.first, cost1 = it.second;
                if (cost1 < mid) continue;     
                long long nd = d + cost1;
                if (nd < dist[x]) {
                    dist[x] = nd;
                    pq.push({nd, x});
                }
            }
        }
        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : edges) adj[it[0]].push_back({it[1], it[2]});

        vector<int> costs;
        for (auto it : edges) costs.push_back(it[2]);
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        int lo = 0, hi = costs.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(adj, online, k, costs[mid], n)) {
                ans = costs[mid];
                lo = mid + 1; 
            } else {
                hi = mid - 1; 
            }
        }
        return ans;
    }
};