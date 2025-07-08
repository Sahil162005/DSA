class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int icolor=image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dcol[]={-1,0,1,0};
        int drow[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            vis[row][col]=1;
            image[row][col]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow= row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=1 && image[nrow][ncol]==icolor){
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};