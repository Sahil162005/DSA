class Solution {
public:
    // vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int,int>mpp;
    //     vector<int>arr;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         mpp[nums[i]]++;
    //     }
    //     for(auto it:mpp){
    //         if(it.second>n/3){
    //             arr.push_back(it.first);
    //         }
    //     }
    //     return arr;
    // }
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>arr;
        int cnt1=0;
        int cnt2=0;
        int ele1=0;
        int ele2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i] == ele1) {
        cnt1++;
        } else if (nums[i] == ele2) {
        cnt2++;
       } else if (cnt1 == 0) {
        ele1 = nums[i];
        cnt1 = 1;
       } else if (cnt2 == 0) {
        ele2 = nums[i];
        cnt2 = 1;
       } else {
        cnt1--;
        cnt2--;
       }
        }
        int cnt3=0;
        int cnt4=0;
        if(cnt1>0){
            for(int i=0;i<n;i++){
                if(nums[i]==ele1){
                    cnt3++;
                }
            }
        }
        if(cnt2>0){
            for(int i=0;i<n;i++){
                if(nums[i]==ele2){
                    cnt4++;
                }
            }
        }
        if(cnt3>n/3){
            arr.push_back(ele1);
        }
        if(cnt4>n/3){
            if(ele1!=ele2){
            arr.push_back(ele2);
            }
        }
        return arr;
    }
};