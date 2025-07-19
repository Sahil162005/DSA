class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>arr;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(k>j){
                sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    arr.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(nums[j]==nums[j-1] && j<k){
                        j++;
                    }
                    while(nums[k]==nums[k+1] && k>j){
                        k--;
                    }
                }

            }
        }
        return arr;
        
    }
};