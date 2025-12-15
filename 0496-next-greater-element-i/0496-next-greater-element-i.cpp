class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    unordered_map<int,int>mpp;
    stack<int>st;
    for(int i=m-1;i>=0;i--){
        if(!st.empty() && st.top()>nums2[i]){
            mpp[nums2[i]]=st.top();
        }
        else {
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty())mpp[nums2[i]]=st.top();
            else{
                mpp[nums2[i]]=-1;
            }
        }
        st.push(nums2[i]);
    }
    for(int i=0;i<n;i++){
        nums1[i]=mpp[nums1[i]];
    }
    return nums1;
    }
};