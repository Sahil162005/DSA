class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>st;
        vector<string>arr;
        int j=0;
        for(int i=1;i<=n;i++){
            if(target[j]==i){
                arr.push_back("Push");
                j++;
            }
            else if(target[j]!=i){
                arr.push_back("Push");
                arr.push_back("Pop");
            }
            if(j==target.size()){
                break;
            }
        }
        return arr;
    }
};