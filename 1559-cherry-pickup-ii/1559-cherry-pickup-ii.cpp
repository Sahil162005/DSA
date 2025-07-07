class Solution {
public:
// 1.)Recursion
    // int fn(int ind,int i,int j,vector<vector<int>>& grid,int m,int n){
    //     if(i<0|| j<0 || i>=n|| j>=n) return -1e8;
    //     if(ind==m-1){
    //         if(i==j){
    //             return grid[ind][i];
    //         }
    //         return grid[ind][i]+grid[ind][j];
    //     }
    //     int maxi=0;
    //     for(int j1=-1;j1<=1;j1++){
    //         for(int j2=-1;j2<=1;j2++){
    //             if(i==j){
    //                 maxi=max(maxi,grid[ind][i]+fn(ind+1,i+j1,j+j2,grid,m,n));
    //             }
    //             else{
    //                 maxi=max(maxi,grid[ind][i]+grid[ind][j]+fn(ind+1,i+j1,j+j2,grid,m,n));
    //             }
    //         }

    //     }
       
    //     return maxi;


    // }
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
        
    //     return fn(0,0,n-1,grid,m,n);
    // }
// 2.)Memoization
     int fn(int ind,int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>&dp){
        if(i<0|| j<0 || i>=n|| j>=n) return -1e8;
        if(ind==m-1){
            if(i==j){
                return grid[ind][i];
            }
            return grid[ind][i]+grid[ind][j];
        }
        if(dp[ind][i][j]!=-1) return dp[ind][i][j];
        int maxi=0;
        for(int j1=-1;j1<=1;j1++){
            for(int j2=-1;j2<=1;j2++){
                if(i==j){
                    maxi=max(maxi,grid[ind][i]+fn(ind+1,i+j1,j+j2,grid,m,n,dp));
                }
                else{
                    maxi=max(maxi,grid[ind][i]+grid[ind][j]+fn(ind+1,i+j1,j+j2,grid,m,n,dp));
                }
            }

        }
       
        return dp[ind][i][j]=maxi;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return fn(0,0,n-1,grid,m,n,dp);
    }
};