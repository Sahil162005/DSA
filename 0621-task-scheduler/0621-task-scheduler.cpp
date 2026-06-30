class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int num = tasks.size();
        if(n==0){
            return num;
        }
        unordered_map<char,int>mpp;
        for(int i=0;i<num;i++){
            mpp[tasks[i]]++;
        }
        if(mpp.size()==1){
            int ans = num + (num-1)*n;
            return ans;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        int cnt =0;
        while(!pq.empty()){
           vector<pair<int,char>>arr;
           int slot = n+1;
           int currtask = 0;
           for(int i=0;i<slot;i++){
            if(!pq.empty()){
                int nu = pq.top().first;
                char ele = pq.top().second;
                pq.pop();
                nu --;
                currtask++;
                if(nu>0){
                    arr.push_back({nu,ele});
                }
            }
           }
           for(auto it:arr){
            pq.push({it.first,it.second});
           }
           if(pq.empty()){
            cnt+=currtask;
           }
           else{
            cnt+=slot;
           }

        }
        return cnt;

    
    }
};