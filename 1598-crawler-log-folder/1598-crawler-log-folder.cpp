class Solution {
public:
    bool isequals(string log,string opp){
        if(log.size()!=opp.size()) return false;
        bool equals=true;
        int i=0,j=0;
        while(i<log.size()){
            if(log[i]==opp[j]){
                i++;
                j++;
            }
            else{
                equals=false;
                break;
            }
        }
        return equals;
    }
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            string log=logs[i];
            if(isequals(log,"./"))continue;
            else if(isequals(log,"../")){
                if(cnt==0) continue;
                cnt--;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};