class Solution {
public:
    // int fn(vector<int>& prices,int ind,int canbuy, vector<vector<int>>&dp){
    //     if(ind>=prices.size()){
    //         return 0;
    //     }
    //     if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
    //     int profit=0;
    //     if(canbuy==1){
    //         int buy=-prices[ind]+fn(prices,ind+1,0,dp);
    //         int skip=fn(prices,ind+1,canbuy,dp);
    //         profit = max(buy, skip);
    //     }
    //     else{
    //         int sell=prices[ind]+fn(prices,ind+2,1,dp);
    //         int skip=fn(prices,ind+1,canbuy,dp);
    //         profit = max(sell, skip);

    //     }
        
    //     return dp[ind][canbuy]=profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return fn(prices,0,1,dp);
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n+2,vector<int>(2,0));
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int canbuy=0;canbuy<=1;canbuy++){
    //             int profit=0;
    //     if(canbuy==1){
    //         int buy=-prices[ind]+dp[ind+1][0];
    //         int skip=dp[ind+1][canbuy];
    //         profit = max(buy, skip);
    //     }
    //     else{
    //         int sell=prices[ind]+dp[ind+2][1];
    //         int skip=dp[ind+1][canbuy];
    //         profit = max(sell, skip);

    //     }
        
    //     dp[ind][canbuy]=profit;

    //         }
    //     }
    //     return dp[0][1];
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,0);
        vector<int>prev1(2,0);
        vector<int>curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int canbuy=0;canbuy<=1;canbuy++){
                int profit=0;
        if(canbuy==1){
            int buy=-prices[ind]+prev[0];
            int skip=prev[canbuy];
            profit = max(buy, skip);
        }
        else{
            int sell=prices[ind]+prev1[1];
            int skip=prev[canbuy];
            profit = max(sell, skip);

        }
        
        curr[canbuy]=profit;

            }
            prev1=prev;
            prev=curr;
        }
        return curr[1];
    }

};