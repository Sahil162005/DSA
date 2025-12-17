class Solution {
public:
    void findnse(vector<int>&nse,vector<int>&arr,int n){
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
    void findpse(vector<int>&pse,vector<int>&arr,int n){
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
    
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long total=0;
        vector<int>nse(n,-1);
        vector<int>pse(n,-1);
        findnse(nse,arr,n);
        findpse(pse,arr,n);
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=(left*right*1ll*arr[i])%mod;
            total=(freq+total)%mod;
        }
        return total;
    }
};