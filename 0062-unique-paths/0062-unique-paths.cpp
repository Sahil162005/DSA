class Solution {
public:
//    1) Recursive Solution
    bool ispossible(int m,int n,int row,int col){
        if(row<0 || row>=m || col<0 || col>=n){
            return false;
        }
        return true;

    }
    // int fn(int m,int n,int row,int col){
    //     if(row==m-1 && col==n-1){
    //         return 1;
    //     }
    //     int down=0,right=0;
    //     if(ispossible(m,n,row+1,col)){
    //         down=fn(m,n,row+1,col);
    //     }
    //     if(ispossible(m,n,row,col+1)){
    //         right=fn(m,n,row,col+1);
    //     }
    //     return down+right;

    // } 
    // int uniquePaths(int m, int n) {
    //     return fn(m,n,0,0);
    // }
// 2.)Memoization
//    int fn(int m,int n,int row,int col,vector<vector<int>>&dp){
//     if(row < 0 || col < 0) return 0;
//     if(row==0 && col==0){
//         return 1;
//     }
//     if(dp[row][col]!=-1) return dp[row][col];
//     dp[row][col]= fn(m,n,row-1,col,dp) + fn(m,n,row,col-1,dp);
//      return dp[row][col];
//    }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return fn(m,n,m-1,n-1,dp);
        
//     }
// 3.) Tabulation
     int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];        
    }

};