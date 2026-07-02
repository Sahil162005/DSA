class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 && health == 1) return false;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dcol[] = {0,1,0,-1};
        int drow[] = {1,0,-1,0};
        while(!pq.empty()){
            int curr = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x==m-1 && y == n-1) return true;
            for(int i=0;i<4;i++){
                int newx = x + drow[i];
                int newy = y + dcol[i];
                if(newx >=0 && newx<m && newy>=0 && newy<n){
                    int newval = curr + grid[newx][newy];
                    if(newval<dist[newx][newy]){
                        dist[newx][newy] = newval;
                        if(newval < health){
                            pq.push({newval,{newx,newy}});
                        }
                    }
                }
            }
        }
        return false;
    }
};