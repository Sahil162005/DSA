class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        if(n==1){
            return nums[0]+1;
        }
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1] +1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        unordered_set<int>mpp(nums.begin(),nums.end());
        while(mpp.count(sum)){
            sum++;
        }
        return sum;

    }
};