class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int tar=0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    tar++;
                }
                if(2*tar>j-i+1){
                    cnt++;
                }
            }
            tar=0;
        }
        return cnt;
    }
};