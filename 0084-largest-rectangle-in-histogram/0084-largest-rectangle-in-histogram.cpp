class Solution {
public:
    void nsefunc(vector<int>&nse,vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && heights[st.top()]<heights[i]){
                nse[i]=st.top();
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    nse[i]=n;
                }
                else{
                    nse[i]=st.top();
                }
            }
            st.push(i);
        }
    }
    void psefunc(vector<int>&pse,vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && heights[st.top()]<heights[i]){
                pse[i]=st.top();
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    pse[i]=-1;
                }
                else{
                    pse[i]=st.top();
                }
            }
            st.push(i);
        }

    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n,0);
        vector<int>pse(n,0);
        nsefunc(nse,heights);
        psefunc(pse,heights);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum=heights[i]*(nse[i]-pse[i]-1);
            ans=max(ans,sum);
        }
        return ans;

    }
};