class Solution {
public: 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int dcol[]={-1,0,1,0};
        int drow[]={0,1,0,-1};
        while(!q.empty()){
            int u=q.front().first.first;
            int v=q.front().first.second;
            int t=q.front().second;
            dis[u][v]=t;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=u+drow[i];
                int ncol=v+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=1){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},t+1});

                }
            }
        }
        return dis;
    }
};