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
    int fn(int ind,int i,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(i<0 || i>=n){
            return INT_MAX;
        }
        if(ind==0){
            return matrix[ind][i];
        }
        if(dp[ind][i]!=INT_MAX) return dp[ind][i];
        int d1=fn(ind-1,i,n,matrix,dp);
        int d2=fn(ind-1,i+1,n,matrix,dp);
        int d3=fn(ind-1,i-1,n,matrix,dp);
        return dp[ind][i]=min({d1,d2,d3})+matrix[ind][i];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            int down= fn(n-1,i,n,matrix,dp);
            if(down<mini){
                mini=down;
            }
        }
        return mini;
    }
};