class Solution {
public:
    void visited(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis){
        queue<pair<int,int>>q;
         int m=grid.size();
        int n=grid[0].size();
        int rows[]={-1,0,1,0};
        int cols[]={0,-1,0,1};
        q.push({row,col});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int currow=rows[i]+x;
                int curcol=cols[i]+y;
                if(currow<m && currow>=0 && curcol<n && curcol>=0){
                    if(grid[currow][curcol]=='1' && vis[currow][curcol]==0){
                        q.push({currow,curcol});
                         vis[currow][curcol]=1;
                    }
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,(vector<int>(n,0)));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    vis[i][j]=1;
                    visited(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};