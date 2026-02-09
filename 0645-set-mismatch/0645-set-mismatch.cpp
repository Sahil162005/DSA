class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int duplicate=0;
        int missing=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                duplicate=nums[i];
            }
            if(nums[i]-nums[i-1]==2){
                missing=nums[i]-1;
            }
        }
        if(nums[0]!=1) missing=1;
        if(nums[n-1]!=n)missing=n;
        return {duplicate,missing};
       
    }
};