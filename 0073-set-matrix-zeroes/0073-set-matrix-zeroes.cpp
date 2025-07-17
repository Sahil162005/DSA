class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zeros;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto it:zeros){
            int row= it.first;
            int col=it.second;
            for(int i=0;i<m;i++){
                matrix[i][col]=0;
            }
            for(int j=0;j<n;j++){
                matrix[row][j]=0;
            }
        }
    }
};