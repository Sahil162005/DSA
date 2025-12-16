class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            if(!st.empty() && st.top()>nums[i%n]){
                arr[i%n]=st.top();
            }
            else{
                while(!st.empty() && st.top()<=nums[i%n]){
                    st.pop();
                }
                if(!st.empty()){
                    arr[i%n]=st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return arr;
       
    }
};