class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n= stations.size();
        int cnt=0;
        if (startFuel >= target) return 0;
        priority_queue<int> pq;
        int limit=startFuel;
        int ans=0;
        int i=0;
        while(limit<target){
            while(i<n && stations[i][0]<=limit){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            limit+=pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};