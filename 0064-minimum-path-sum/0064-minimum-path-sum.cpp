class Solution {
public:
// 1.)Recursion
// int maxi=INT_MAX;
//   bool ispossible(int m,int n,int row,int col){
//     if(row<0 || row>=m || col<0 || col>=n){
//             return false;
//         }
//         return true;
//   }
//   void fn(int m,int n,int row,int col,vector<vector<int>>&grid,int sum){
//     sum += grid[row][col];
//         if(row==m-1 && col==n-1){
//             if(sum<maxi){
//                 maxi=sum;
//             }
//             return;
//         }

//         if (ispossible(m,n,row+1,col)){
//             fn(m,n,row+1,col,grid,sum);
//         }
//         if (ispossible(m,n,row,col+1)){
//             fn(m,n,row,col+1,grid,sum);
//         }

//     } 
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         fn(m,n,0,0,grid,0);
//         return maxi;
//     }
// 
// 2.)Memoization
//   int fn(int m,int n,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
//     if(row<0 || row>=m || col<0 || col>=n){
//             return INT_MAX;
//         }
//     if(dp[row][col]!=-1)return dp[row][col];
//         if(row==0 && col==0){
//             return grid[0][0];
//         }
//         int down=0,right=0;

        
//            down= fn(m,n,row-1,col,grid,dp);
//             right=fn(m,n,row,col-1,grid,dp);
        
//         dp[row][col]=min(down,right)+grid[row][col];
//         return dp[row][col];

//     } 
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return fn(m,n,m-1,n-1,grid,dp);
//     }
// 3.)Tabulation
int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                else{
                    int down=INT_MAX,right=INT_MAX;
                    if(i>0){
                        down=dp[i-1][j];
                    }
                    if(j>0){
                        right=dp[i][j-1];
                    }
                    dp[i][j]=min(down,right)+grid[i][j];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};