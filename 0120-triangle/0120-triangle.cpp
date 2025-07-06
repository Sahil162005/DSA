class Solution {
public: 
    bool ispossible(int ind,int i,vector<vector<int>>&triangle){
        if(i<0 || i>=triangle[ind].size()){
            return false;
        }
        return true;
    }
    int fn(int ind,int i,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(ind==0){
            return triangle[0][0];
        }
        if(dp[ind][i]!=INT_MAX) return dp[ind][i];
        int d1=INT_MAX,d2=INT_MAX;
        if(ispossible(ind-1,i,triangle)){
        d1=fn(ind-1,i,triangle,dp)+triangle[ind][i];
        }
        if(ispossible(ind-1,i-1,triangle)){
        d2=fn(ind-1,i-1,triangle,dp)+triangle[ind][i];
        }
        return dp[ind][i] =min(d1,d2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1 && triangle[0].size()==1){
            return triangle[0][0];
        }
        vector<vector<int>> dp;
       for (int i = 0; i < triangle.size(); ++i) {
            dp.push_back(vector<int>(triangle[i].size(), INT_MAX));
        }
        int mini=INT_MAX;
        int m=triangle.size();
        for(int i=0;i<triangle[m-1].size();i++){
            int val=fn(m-1,i,triangle,dp);
            if(val<mini){
                mini=val;
            }
        }
        return mini;
        
        
    }
};