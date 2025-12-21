class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
               int element=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,element*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=arr[st.top()];
                st.pop();
                int nse=n;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,element*(nse-pse-1));

        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>arr1(n,vector<int>(m));
        for(int i=0;i<m;i++){
            int val=0;
            for(int j=0;j<n;j++){
                int curr=matrix[j][i]-'0';
                if(curr==0) val=0;
                val+=curr;
                arr1[j][i]=val;

            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,largestRectangleArea(arr1[i]));
        }
        return maxi;
    }
};