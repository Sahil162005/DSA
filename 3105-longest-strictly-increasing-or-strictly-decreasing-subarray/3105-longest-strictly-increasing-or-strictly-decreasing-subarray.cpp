class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int maxcnt = 1;
        int ele = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>ele){
                cnt++;
                maxcnt = max(cnt,maxcnt);
                ele = nums[i];
            }
            else if(nums[i]<=ele){
                cnt = 1;
                ele = nums[i];
            }
        }
        ele = nums[n-1];
        cnt = 1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]>ele){
                cnt++;
                maxcnt = max(cnt,maxcnt);
                ele = nums[i];
            }
            else if(nums[i]<=ele){
                cnt = 1;
                ele = nums[i];
            }

        }
        return maxcnt;

    }
};