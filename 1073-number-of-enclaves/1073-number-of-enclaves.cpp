class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=0;
                }
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 &&(i==0 || i==m-1 || j==0 || j==n-1)){
                    vis[i][j]=1;
                    q.push({i,j});

                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int u=q.front().first;
            int v=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=u+drow[i];
                int col=v+dcol[i];
                if(row>=0 && row<m && col>=0 && col<n && vis[row][col]!=1){
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};