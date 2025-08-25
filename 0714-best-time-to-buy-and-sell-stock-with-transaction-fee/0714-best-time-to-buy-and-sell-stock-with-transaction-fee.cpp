class Solution {
public:
    int fn(vector<int>& prices,int ind,int canbuy,int fee,vector<vector<int>>&dp){
        if(ind==prices.size()){
            return 0;
        }
        int profit=0;
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        if(canbuy==1){
            int buy=-prices[ind]+fn(prices,ind+1,0,fee,dp);
            int skip=fn(prices,ind+1,canbuy,fee,dp);
            profit=max(buy,skip);
        }
        else{
            int sell=prices[ind]-fee+fn(prices,ind+1,1,fee,dp);
            int skip=fn(prices,ind+1,canbuy,fee,dp);
            profit=max(sell,skip);
        }
        return dp[ind][canbuy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(prices,0,1,fee,dp);
    }
};