class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        int time=0;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        while(!q.empty()){
            int el=q.front().first;
            int ind=q.front().second;
            time++;
            if(ind==k){
                if(el==1){
                break;
                }
            }
            el=el-1;
            q.pop();
            if(el==0){
                continue;
            }
            q.push({el,ind});
            

        }
        return time;

    }
};