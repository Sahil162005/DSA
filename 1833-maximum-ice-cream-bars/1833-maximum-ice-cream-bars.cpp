class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int cnt=0;
        int total = coins;
        for(int i=0;i<n;i++){
            if(costs[i]<=total){
                cnt++;
                total-=costs[i];
            }
        }
        return cnt;
    }
};