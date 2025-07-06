class Solution {
public:
// 1.)Mmeoization 
    // bool ispossible(int ind,int i,vector<vector<int>>&triangle){
    //     if(i<0 || i>=triangle[ind].size()){
    //         return false;
    //     }
    //     return true;
    // }
    // int fn(int ind,int i,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    //     if(ind==0){
    //         return triangle[0][0];
    //     }
    //     if(dp[ind][i]!=INT_MAX) return dp[ind][i];
    //     int d1=INT_MAX,d2=INT_MAX;
    //     if(ispossible(ind-1,i,triangle)){
    //     d1=fn(ind-1,i,triangle,dp)+triangle[ind][i];
    //     }
    //     if(ispossible(ind-1,i-1,triangle)){
    //     d2=fn(ind-1,i-1,triangle,dp)+triangle[ind][i];
    //     }
    //     return dp[ind][i] =min(d1,d2);
    // }
    
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     if(triangle.size()==1 && triangle[0].size()==1){
    //         return triangle[0][0];
    //     }
    //     vector<vector<int>> dp;
    //    for (int i = 0; i < triangle.size(); ++i) {
    //         dp.push_back(vector<int>(triangle[i].size(), INT_MAX));
    //     }
    //     int mini=INT_MAX;
    //     int m=triangle.size();
    //     for(int i=0;i<triangle[m-1].size();i++){
    //         int val=fn(m-1,i,triangle,dp);
    //         if(val<mini){
    //             mini=val;
    //         }
    //     }
    //     return mini; 
    // }

    // 2.)Tabulation
     int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1 && triangle[0].size()==1){
            return triangle[0][0];
        }
        vector<vector<int>> dp;
       for (int i = 0; i < triangle.size(); ++i) {
            dp.push_back(vector<int>(triangle[i].size(), INT_MAX));
        }
        int m=triangle.size();
        dp[0][0]=triangle[0][0];
        int mini=INT_MAX;
        for(int i=1;i<m;i++){
            mini=INT_MAX;
            for(int j=0;j<triangle[i].size();j++){
                int d1=INT_MAX,d2=INT_MAX;
                if(j< triangle[i-1].size()){
                d1=dp[i-1][j];}
                if(j-1>=0 || j-1<triangle[i-1].size()){
                    d2=dp[i-1][j-1];
                }
                dp[i][j]=min(d1,d2)+triangle[i][j];
                if(mini>dp[i][j]){
                    mini=dp[i][j];                }

            }
        }
       
        return mini; 
    }
};