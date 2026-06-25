class Solution {
public:
    static bool compare(const vector<int>&a ,const vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(intervals.begin(),intervals.end(),compare);
        for(int i=0;i<n;i++){
            if(pq.empty()){
                pq.push(intervals[i][1]);
            }
            else{
                if(intervals[i][0]>pq.top()){
                    pq.pop();
                }
                pq.push(intervals[i][1]);
            }
        }
        return pq.size();

    }
};