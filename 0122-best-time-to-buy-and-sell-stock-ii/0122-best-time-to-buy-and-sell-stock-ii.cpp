class Solution {
public:
    int fn(vector<int>&prices,int ind,vector<vector<int>>&dp,int canbuy){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        int profit = 0;
        
        if(canbuy == 1) {
            int buy = -prices[ind] + fn(prices, ind + 1, dp, 0); 
            int skip = fn(prices, ind + 1, dp, 1);               
            profit = max(buy, skip);
        }
        else {
            int sell = prices[ind] + fn(prices, ind + 1, dp, 1); 
            int skip = fn(prices, ind + 1, dp, 0); 
            profit = max(sell, skip);
        }
         return dp[ind][canbuy] = profit;

    }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return fn(prices,0,dp,1);
        
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2,0));
    //     vector<int>prev(2,0);
    //     vector<int>curr(2,0);
    //     dp[n][0]=0,dp[n][1]=0;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<=1;j++){
    //             int profit = 0;
    //             if(j==1){
    //                 int buy = -prices[i] + dp[i+1][0];
    //                 int skip = dp[i+1][1];             
    //                  profit = max(buy, skip);
    //             }
    //             else{
    //                 int sell=prices[i]+dp[i+1][1];
    //                 int skip=dp[i+1][0];
    //                 profit = max(sell, skip);

    //             }
    //             dp[i][j]=profit;

    //         }
    //     }
    //     return dp[0][1];
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit = 0;
                if(j==1){
                    int buy = -prices[i] + prev[0];
                    int skip = prev[1];             
                     profit = max(buy, skip);
                }
                else{
                    int sell=prices[i]+prev[1];
                    int skip=prev[0];
                    profit = max(sell, skip);
                }
                curr[j]=profit;

            }
            prev=curr;
        }
       return curr[1];
    }
};