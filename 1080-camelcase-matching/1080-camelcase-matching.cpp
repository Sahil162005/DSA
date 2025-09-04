class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>arr;
        int n=queries.size();
        for(int i=0;i<n;i++){
            int j=0;
            int k=0;
            int len=queries[i].size();
            bool ans=true;
            while(j<len && k<pattern.size()){
                if(queries[i][j]==pattern[k]){
                    j++;
                    k++;
                }
                else if(queries[i][j]!=pattern[k]){
                    if(isupper(queries[i][j])){
                        ans=false;
                        break;
                    }
                    else{
                        j++;
                    }
                }
            }
            while(j<len){
                if(isupper(queries[i][j])){
                        ans=false;
                        break;
                    }
                j++;
            }
            if(k!=pattern.size()){
                ans=false;
            }
            arr.push_back(ans);
        }
        return arr;
        
    }
};