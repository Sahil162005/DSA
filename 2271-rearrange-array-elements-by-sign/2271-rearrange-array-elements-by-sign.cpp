class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int>arr;
        // int n=nums.size();
        // int i=0;
        // int j=0;
        // while(i<n && j<n){
        //     if(nums[i]>0){arr.push_back(nums[i]);}
        //     else if(nums[i]<0){
        //         while(i<n){
        //             if(nums[i]>0){
        //                 arr.push_back(nums[i]);
        //                 break;
        //             }
        //             i++;
        //         }
        //     }
        //     if(nums[j]<0){
        //         arr.push_back(nums[j]);
        //     }
        //     else if(nums[j]>0){
        //         while(j<n){
        //             if(nums[j]<0){
        //                 arr.push_back(nums[j]);
        //                 break;
        //             }
        //             j++;
        //         }
        //     }
        //     i++,j++;
        // }
        // return arr;
        int n=nums.size();
        vector<int>arr;
        int neg=0;
        int pos=0;
        while(pos<n && neg<n){
            if(nums[pos]>0){
                arr.push_back(nums[pos]);
            }
            else if(nums[pos]<0 && pos<n){
                while(nums[pos]<0){
                    pos++;
                }
                arr.push_back(nums[pos]);
            }
            if(nums[neg]<0){
                arr.push_back(nums[neg]);
            }
            else if(nums[neg]>0){
                while(nums[neg]>0 && neg<n){
                    neg++;
                }
                arr.push_back(nums[neg]);
            }
            pos++,neg++;
        }
        return arr;

    }
};