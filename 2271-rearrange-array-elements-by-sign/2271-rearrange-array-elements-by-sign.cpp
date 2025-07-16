class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        int i=0;
        int j=0;
        while(i<n && j<n){
            if(nums[i]>0){arr.push_back(nums[i]);}
            else if(nums[i]<0){
                while(i<n){
                    if(nums[i]>0){
                        arr.push_back(nums[i]);
                        break;
                    }
                    i++;
                }
            }
            if(nums[j]<0){
                arr.push_back(nums[j]);
            }
            else if(nums[j]>0){
                while(j<n){
                    if(nums[j]<0){
                        arr.push_back(nums[j]);
                        break;
                    }
                    j++;
                }
            }
            i++,j++;
        }
        return arr;

    }
};