class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int m,int n,int i,int j){
        int dcol[]={0,1,0,-1};
        int drow[]={1,0,-1,0};
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int crow = row + drow[k];
                int ccol = col + dcol[k];
                if(crow>=0 && crow<m && ccol>=0 && ccol<n && vis[crow][ccol]==0 && grid[crow][ccol]==1){
                    q.push({crow,ccol});
                    vis[crow][ccol]=1;
                }
            }
        }
    }
    bool bfs2(vector<vector<int>>& grid,vector<vector<int>>&vis1,vector<vector<int>>&vis2,int i,int j,int m,int n){
        int dcol[]={0,1,0,-1};
        int drow[]={1,0,-1,0};
        queue<pair<int,int>>q;
        q.push({i,j});
        bool ans=true;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(vis1[row][col]==0){
                ans=false;
            }
            for(int k=0;k<4;k++){
                int crow = row + drow[k];
                int ccol = col + dcol[k];
                if(crow>=0 && crow<m && ccol>=0 && ccol<n && vis2[crow][ccol]==0 && grid[crow][ccol]==1){
                    q.push({crow,ccol});
                    vis2[crow][ccol]=1;
                }
            }

        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>>vis1(m,vector<int>(n,0));
        vector<vector<int>>vis2(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==1 && vis1[i][j]==0){
                    vis1[i][j]=1;
                    bfs(grid1,vis1,m,n,i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && vis2[i][j]==0){
                    vis2[i][j]=1;
                    if(bfs2(grid2,vis1,vis2,i,j,m,n)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};