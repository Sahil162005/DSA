class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxi=0;
        int j=nums.size()-1;
        int i=0;
        while(i<=j){
            int area= min(nums[i],nums[j])*(j-i);
            maxi=max(area,maxi);
            if(nums[i]<nums[j]){
                i++;
            }
            else{
                j--;
            }

        }
        return maxi;
    }
};