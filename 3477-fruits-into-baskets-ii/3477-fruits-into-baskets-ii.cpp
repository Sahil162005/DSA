class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int fruit=fruits[i];
            bool canbeplaced=false;
            int j=0;
            while(j<n){
                if(baskets[j]>=fruit){
                    canbeplaced=true;
                    baskets[j]=-1;
                    break;
                }
                j++;
            }
            if(!canbeplaced){
                cnt++;
            }
        }
        return cnt;
    }
};