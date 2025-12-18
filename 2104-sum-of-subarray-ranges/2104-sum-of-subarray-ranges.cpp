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
     void findnge(vector<int>&nge,vector<int>&arr,int n){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            else{
                nge[i]=n;
            }
            st.push(i);
        }

    }
    void findpge(vector<int>&pge,vector<int>&arr,int n){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pge[i]=st.top();
            }
            else{
                pge[i]=-1;
            }
            st.push(i);
        }
    }
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        long long total1=0;
        long long total2=0;
        vector<int>nse(n,-1);
        vector<int>pse(n,-1);
        vector<int>nge(n,-1);
        vector<int>pge(n,-1);
        findnse(nse,arr,n);
        findpse(pse,arr,n);
        findnge(nge,arr,n);
        findpge(pge,arr,n);
        for(int i=0;i<n;i++){
            int left1=i-pse[i];
            int right1=nse[i]-i;
            int left2=i-pge[i];
            int right2=nge[i]-i;
            long long freq1=(left1*right1*1ll*arr[i]);
            long long freq2=(left2*right2*1ll*arr[i]);
            total1=(freq1+total1);
            total2=(freq2+total2);
        }
        return (total2-total1);

    }
};