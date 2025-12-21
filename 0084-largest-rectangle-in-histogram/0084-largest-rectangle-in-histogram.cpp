class Solution {
public:
    void findnse(vector<int>&arr,vector<int>&nse,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            else{
                nse[i]=n;
            }
            st.push(i);
        }
    }
    void findpse(vector<int>&arr,vector<int>&pse,int n){
         stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            else{
                pse[i]=-1;
            }
            st.push(i);
        }
        
    }
    // int largestRectangleArea(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<int>nse(n);
    //     vector<int>pse(n);
    //     findnse(arr,nse,n);
    //     findpse(arr,pse,n);
    //     int maxi=0;
    //     for(int i=0;i<n;i++){
    //         int area=arr[i]*(nse[i]-pse[i]-1);
    //         maxi=max(area,maxi);
    //     }
    //     return maxi;

        
    // }
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
};