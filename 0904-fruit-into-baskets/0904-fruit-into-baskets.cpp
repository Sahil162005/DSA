class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=-1;
        int second=-1;
        int firstpos=-1,secondpos=-1;
        int l=0,r=0;
        int n=fruits.size();
        int maxlen=0;
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                // while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
                // }
            }
            if(mpp.size()<=2){
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            r++;
            }
        
        return maxlen;
        
    }
};