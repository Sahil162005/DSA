class Solution {
public:
//    1) Recursive Solution
   
    // int fn(int m,int n,int row,int col,vector<vector<int>>& obstacleGrid){
    //     if(row==m-1 && col==n-1){
    //         return 1;
    //     }
    //     if(row<0 || row>=m || col<0 || col>=n){
    //         return 0;
    //     }
    //     if(obstacleGrid[row][col]==1){
    //         return 0;
    //     }
    //     int down=0,right=0;
    //         down=fn(m,n,row+1,col,obstacleGrid);
    //         right=fn(m,n,row,col+1,obstacleGrid);
    //     return down+right;

    // } 
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     if(obstacleGrid[m-1][n-1]==1) return 0;
    //     return fn(m,n,0,0,obstacleGrid);
    // }
// 2.) Memoization
  int fn(int m,int n,int row,int col,vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp){
     if(row<0 || row>=m || col<0 || col>=n){
            return 0;
        }
        if(obstacleGrid[row][col]==1){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
         if(row==0 && col==0){
            return 1;
        }
        dp[row][col]=fn(m,n,row-1,col,obstacleGrid,dp)+fn(m,n,row,col-1,obstacleGrid,dp);
        return dp[row][col];

    } 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[m-1][n-1]==1) return 0;
        return fn(m,n,m-1,n-1,obstacleGrid,dp);
    }
};