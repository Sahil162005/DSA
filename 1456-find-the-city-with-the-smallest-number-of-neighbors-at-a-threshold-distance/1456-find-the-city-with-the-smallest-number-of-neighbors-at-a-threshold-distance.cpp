class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>>matrix(n,vector<long long>(n,INT_MAX));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) matrix[i][j]=0;
                    else{
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
        int cnt;
        int mini=INT_MAX;
        int minnode;
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(matrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<mini){
                mini=cnt;
                minnode=i;
            }
            if(cnt==mini){
                minnode=max(i,minnode);
            }
        }
        return minnode;
        
    }
};