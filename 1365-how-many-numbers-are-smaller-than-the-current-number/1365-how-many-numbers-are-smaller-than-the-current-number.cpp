class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
                mpp[arr[i]]=i;
            }
            
        }
        for(int i=0;i<nums.size();i++){
            arr[i]=mpp[nums[i]];

        }
        return arr;
    }
};