class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        long long score=0;
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
            int element=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            score+=element;
            nums[index]=ceil(nums[index] / 3.0);
            pq.push({nums[index],index});
        }
        return score;

    }
};