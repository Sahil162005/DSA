class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int cost=0;
        for(int i=1;i<n;i++){
            cost=max(cost,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return cost;

    }
};