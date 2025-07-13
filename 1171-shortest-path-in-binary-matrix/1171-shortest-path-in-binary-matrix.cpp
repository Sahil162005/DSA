class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        int dcol[]={0,-1,0,1,1,1,-1,-1};
        int drow[]={1,0,-1,0,1,-1,-1,1};
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) vis[i][j]=0;
            }
        }
        int cnt=INT_MAX;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            if(x==n-1 && y==n-1){
                cnt=min(dis,cnt);
            }
            for(int k=0;k<8;k++){
                int row=x+drow[k];
                int col=y+dcol[k];
                if(row>=0 && row<n && col>=0 && col<n && vis[row][col]!=1){
                    vis[row][col]=1;
                    q.push({{row,col},dis+1});
                }
            }

        }
        if(cnt==INT_MAX) return -1;
        return cnt;
    }
};