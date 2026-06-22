class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,float>mpp;
        string req = "balon";
        for(int i=0;i<req.size();i++){
            mpp[req[i]]=0;
        }
        for(int i=0;i<n;i++){
            if(mpp.find(text[i])!=mpp.end()){
                if(text[i]=='l' || text[i]=='o'){
                    mpp[text[i]]+=0.5;
                }
                else{
                    mpp[text[i]]++;
                }
            }
        }
        int mini = INT_MAX;
        for(auto it : mpp){
            mini = min((int)it.second,mini);
        }
        return mini;

        
    }
};