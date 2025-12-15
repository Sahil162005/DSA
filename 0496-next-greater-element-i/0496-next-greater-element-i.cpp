class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    for(int i=0;i<n;i++){
        int val=nums1[i];
        int res=-1;
        int fnd=0;
        for(int j=0;j<m;j++){
            if(nums2[j]==val)fnd=1;
            if(fnd==0)continue;
            if(nums2[j]>val){
                res=nums2[j];
                break;
            }
        }
        nums1[i]=res;

    }
    return nums1;
    }
};