class Solution {
public:
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     vector<vector<pair<int,int>>>adj(n+1);
    //     vector<int>dis(n+1,INT_MAX);
    //     dis[k]=0;
    //     for(auto it: times){
    //         int u =it[0];
    //         int v=it[1];
    //         int w=it[2];
    //         adj[u].push_back({v,w});
    //     }
    //     queue<pair<int,int>>q;
    //     q.push({k,0});
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         int w=q.front().second;
    //         q.pop();
    //         for(auto it: adj[node]){
    //             int c=it.first;
    //             int weight=it.second;
    //             if(dis[c]>w+weight){
    //                 dis[c]=w+weight;
    //                 q.push({c,dis[c]});
    //             }
    //         }
    //     }
    //     int maxi=-1;
    //     for(int i=1;i<=n;i++){
    //         if(dis[i]==INT_MAX) return -1;
    //         maxi=max(maxi,dis[i]);
    //     }
    //     return maxi;
    // }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        for(auto it: times){
            int u =it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({k,0});
        while(!q.empty()){
            int node=q.top().first;
            int w=q.top().second;
            q.pop();
            for(auto it: adj[node]){
                int c=it.first;
                int weight=it.second;
                if(dis[c]>w+weight){
                    dis[c]=w+weight;
                    q.push({c,dis[c]});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            maxi=max(maxi,dis[i]);
        }
        return maxi;
    }
};