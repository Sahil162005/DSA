class Solution {
public:
    // int fn(vector<int>& g, vector<int>& s,int index,int cnt,vector<vector<int>>&dp){
    //     if(index==g.size()|| cnt==s.size()){
    //         return 0;
    //     }
    //      if(dp[index][cnt]!=-1)return dp[index][cnt];
    //     int maxi=0;
    //     int nottake=0+fn(g,s,index,cnt+1,dp);
    //     int take=0;
    //     if(g[index]<=s[cnt]){
    //         take=1+fn(g,s,index+1,cnt+1,dp);
    //     }
    //     maxi=max(take,nottake);
    //     return dp[index][cnt]=maxi;
    // }
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(g.begin(), g.end());
    //    sort(s.begin(), s.end());
    //     vector<vector<int>>dp(g.size(),vector<int>(s.size(),-1));
    //     return fn(g,s,0,0,dp);
    // }
    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0,j=0;
        int cnt=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        } 
        return cnt;
    }
};