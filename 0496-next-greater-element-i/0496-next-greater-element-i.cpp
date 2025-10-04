class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>arr(n,-1);
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int i=m-1;i>=0;i--){
            if(!st.empty()&&nums2[i]<st.top()){
                mpp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(!st.empty()){
                    mpp[nums2[i]]=st.top();
                }
                else if(st.empty()){
                    mpp[nums2[i]]=-1;
                }
                st.push(nums2[i]);
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=mpp[nums1[i]];
        }
        return arr;
    }
};