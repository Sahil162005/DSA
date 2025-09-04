class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        if(nums[0]>nums[1])return 0;
        int mid;
        int start=0;
        int end=n-2;
        int ind;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                ind=mid;
                break;
            }
            else if(nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                end=mid;
            }
        }
        return ind;
        
    }
};