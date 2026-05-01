class Solution {
public:
    int fn(vector<vector<int>>& grid, int ind,int j1,int j2,  vector<vector<vector<int>>>&dp){
        if(ind==grid.size()){
            return 0;
        }
        if(dp[ind][j1][j2]!=-1){
            return dp[ind][j1][j2];
        }
        int curr=0;
        if(j1==j2){
            curr+=grid[ind][j1];
        }
        else if(j1!=j2){
            curr+=grid[ind][j1] + grid[ind][j2];
        }
        int take=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(j1+i >=0 && j1+i<grid[0].size() && j2+j >=0 && j2+j<grid[0].size()){
                take = max(take,curr + fn(grid,ind+1,j1+i,j2+j,dp));
                }
            }
        }
        return dp[ind][j1][j2]=take;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return fn(grid,0,0,grid[0].size()-1,dp);
    }
};