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
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n);
        vector<int>pse(n);
        findnse(arr,nse,n);
        findpse(arr,pse,n);
        int maxi=0;
        for(int i=0;i<n;i++){
            int area=arr[i]*(nse[i]-pse[i]-1);
            maxi=max(area,maxi);
        }
        return maxi;

        
    }
};