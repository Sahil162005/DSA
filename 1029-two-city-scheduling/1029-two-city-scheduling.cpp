class Solution {
public:
   static bool compare(const vector<int>&a,const vector<int>&b){
    return (a[0] - a[1])<(b[0]-b[1]);
   }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(),costs.end(),compare);
        int total= 0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                total += costs[i][0];
            }
            else{
                total+=costs[i][1];
            }
        }
        return total;
    }
};