class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return 0;
        }
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        int dcol[] = {0,1,0,-1};
        int drow[] = {1,0,-1,0};
        while(!q.empty()){
            int prev = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int i =0;i<4;i++){
                int newx = x + drow[i];
                int newy = y + dcol[i];
                if(newx >=0 && newx<n && newy>=0 && newy<n){
                    if(dis[newx][newy]>prev+1){
                        dis[newx][newy] = prev+1;
                        q.push({prev+1,{newx,newy}});
                    }
                }
            }
        }
        vector<vector<int>>dist(n,vector<int>(n,-1));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dis[0][0],{0,0}});
         while(!pq.empty()){
            int prev = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == n - 1 && y == n - 1) return prev;
            for(int i =0;i<4;i++){
                int newx = x + drow[i];
                int newy = y + dcol[i];
                if(newx >=0 && newx<n && newy>=0 && newy<n){
                    int nsafe = min(dis[newx][newy],prev);
                    if(dist[newx][newy]<nsafe){
                        dist[newx][newy] = nsafe;
                        pq.push({nsafe,{newx,newy}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
        
        
    }
};