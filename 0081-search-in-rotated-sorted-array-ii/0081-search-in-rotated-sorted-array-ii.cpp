class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int pivot=0;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target)return true;
            if(nums[mid]==nums[end] && nums[mid]==nums[start]){
                start++;
                end--;
                continue;
            }
            else if(nums[start]<=nums[mid]){
                if(target<nums[mid] && target >=nums[start]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target>=nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }

        return false;
    }
};