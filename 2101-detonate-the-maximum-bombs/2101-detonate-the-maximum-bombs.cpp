class Solution {
public:
    int bfs(int node, vector<int>&vis,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        int cnt=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[curr]){
                if(vis[it]!=1){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return cnt;

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>adj(n);
        for(int i = 0;i <n;i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j) continue;
            long long x2 = bombs[j][0];
            long long y2 = bombs[j][1];
            long long r2 = bombs[j][2];
            long long dis = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
            if(dis <= r1*r1){
                adj[i].push_back(j);
            }
        }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            vis[i]=1;
            maxi = max(maxi,bfs(i,vis,adj));
        }
        return maxi;
    }
};