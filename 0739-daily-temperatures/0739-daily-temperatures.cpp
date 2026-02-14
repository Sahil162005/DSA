class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>arr(n,0);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty() && st.top().first >temperatures[i]){
                arr[i]=st.top().second-i;
            }
            else{
                while(!st.empty() && st.top().first <= temperatures[i]){
                    st.pop();
                }
                if(!st.empty()){
                    arr[i]=st.top().second-i;
                }
                else{
                    arr[i]=0;
                }
            }
            st.push({temperatures[i],i});
        }
        return arr;
    }
};