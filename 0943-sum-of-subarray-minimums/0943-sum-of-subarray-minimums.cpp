class Solution {
public:
    void findnse(vector<int>& nse,vector<int>& arr,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && arr[st.top()]<arr[i]){
                nse[i]=st.top();
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    nse[i]=st.top();
                }
                else if(st.empty()){
                    nse[i]=n;
                }
            }
            st.push(i);
        }
    }
    void findpse(vector<int>& pse,vector<int>& arr,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        vector<int>nse(n,-1);
        vector<int>pse(n,-1);
        findnse(nse,arr,n);
        findpse(pse,arr,n);
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=left*right*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};