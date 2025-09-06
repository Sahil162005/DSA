class Solution {
public:
    void solve(string num,int target,int ind,vector<string>&ans,string s,long long temp,long long prev){
        if(ind==num.size()){
        if(temp==target){
            ans.push_back(s);
        }
        return;
        }
        for(int i=ind;i<num.size();i++){
            string curr=num.substr(ind,i-ind+1);
            if(curr.size()>1 && curr[0]=='0'){
                break;
            }
            long long numb=stol(curr);
            if(ind==0){
                solve(num,target,i+1,ans,curr,numb,numb);
            }
            else{
                //*
                solve(num,target,i+1,ans,s+"*"+curr,temp - prev + prev * numb, prev * numb);
                //+
                solve(num,target,i+1,ans,s+"+"+curr,temp+numb,numb);
                //-
                solve(num,target,i+1,ans,s+"-"+curr,temp-numb,-numb);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        string s="";
        s+=num[0];
        int temp=num[0]-'0';
        solve(num,target,0,ans,s,temp,temp);
        return ans;
        
    }
};