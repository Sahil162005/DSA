class Solution {
public: 
// 1.)Recusive Soln
    // int fn(int ind,int i,int n,vector<vector<int>>& matrix){
    //     if(i<0 || i>=n){
    //         return INT_MAX;
    //     }
    //     if(ind==n-1){
    //         return matrix[ind][i];
    //     }
    //     int d1=fn(ind+1,i,n,matrix);
    //     int d2=fn(ind+1,i+1,n,matrix);
    //     int d3=fn(ind+1,i-1,n,matrix);
    //     return min({d1,d2,d3})+matrix[ind][i];

    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int mini=INT_MAX;
    //     for(int i=0;i<n;i++){
    //         int down= fn(0,i,n,matrix);
    //         if(down<mini){
    //             mini=down;
    //         }
    //     }
    //     return mini;
    // }

    // 2.)Memoization soln
    // int fn(int ind,int i,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    //     if(i<0 || i>=n){
    //         return INT_MAX;
    //     }
    //     if(ind==0){
    //         return matrix[ind][i];
    //     }
    //     if(dp[ind][i]!=INT_MAX) return dp[ind][i];
    //     int d1=fn(ind-1,i,n,matrix,dp);
    //     int d2=fn(ind-1,i+1,n,matrix,dp);
    //     int d3=fn(ind-1,i-1,n,matrix,dp);
    //     return dp[ind][i]=min({d1,d2,d3})+matrix[ind][i];

    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int mini=INT_MAX;
    //     vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
    //     for(int i=0;i<n;i++){
    //         int down= fn(n-1,i,n,matrix,dp);
    //         if(down<mini){
    //             mini=down;
    //         }
    //     }
    //     return mini;
    // }
// 3.)Tabulation
  int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
         for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int d1=INT_MAX,d2=INT_MAX,d3=INT_MAX;
                if(j-1 >=0){
                    d1=dp[i-1][j-1];
                }
                if(j+1<n){
                    d2=dp[i-1][j+1];
                }
                d3=dp[i-1][j];
                dp[i][j]=min({d1,d2,d3})+matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            if(dp[n-1][i] < mini){
                mini=dp[n-1][i];
                }
        }
        return mini;
    }
};