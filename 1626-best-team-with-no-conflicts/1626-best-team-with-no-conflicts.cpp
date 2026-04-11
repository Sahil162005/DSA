class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            scores[i]=arr[i].second;
            ages[i]=arr[i].first;
        }
        int maxi=0;
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++){
            dp[i]=arr[i].second;
            for(int j=0;j<i;j++){
                if(arr[j].second<=arr[i].second){
                    dp[i]=max(dp[i],arr[i].second+dp[j]);
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};