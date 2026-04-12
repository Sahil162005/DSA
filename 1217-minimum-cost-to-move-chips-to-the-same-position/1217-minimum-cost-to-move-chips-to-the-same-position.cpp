class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
       int evencnt=0;
       int oddcnt=0;
       for(int i=0;i<n;i++){
        if(position[i]%2==0){
            evencnt++;
        }
        else{
            oddcnt++;
        }
       }
       return min(evencnt,oddcnt);
    }
};