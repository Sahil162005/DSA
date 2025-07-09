class Solution {
public: 
    void dfs (int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,int m,int n){
        vis[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int row=i+drow[k];
            int col=j+dcol[k];
            if(row<m && row>=0 && col<n && col>=0 && vis[row][col]!=1){
                dfs(row,col,vis,board,m,n);
            }
            }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    vis[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==m-1 || j==n-1)){
                    dfs(i,j,vis,board,m,n);
                }
            }
        }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};