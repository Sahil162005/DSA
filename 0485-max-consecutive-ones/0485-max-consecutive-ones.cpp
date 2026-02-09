class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                cnt=0;
            }
            else{
                cnt++;
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};