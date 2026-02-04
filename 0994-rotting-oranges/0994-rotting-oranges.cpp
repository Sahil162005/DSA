class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                vis[i][j]=grid[i][j];
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int tm=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(t,tm);
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1 && vis[row][col]!=2){
                    q.push({{row,col},t+1});
                    vis[row][col]=2;

                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1) return -1;
            }
        }
      return tm;

    }
};