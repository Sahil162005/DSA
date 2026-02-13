class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) { 
        stack<pair<int,int>>st;
        vector<int>arr(n,0);
        int prev=0;
        for(int i=0;i<logs.size();i++){
            int cnt=0;
            int id=0;
            int time=0;
            string opp="";
           string cur = "";
           for (char c : logs[i]) {
            if (c == ':') {
             if(cnt==0){
                id=stoi(cur);
                cnt++;
             }
             else if(cnt==1){
                opp=cur;
                cnt++;
             }
             cur = "";
            } else {
            cur += c;
            }
            }
            time=stoi(cur);
            if(opp=="start"){
                if(!st.empty()){
                    arr[st.top().first]+=time-prev;
                }
                prev=time;
                st.push({id,time});
            }
            else{
                arr[id]+=time-prev+1;
                st.pop();
                prev=time+1;
            }
        }
        return arr;
    }
};