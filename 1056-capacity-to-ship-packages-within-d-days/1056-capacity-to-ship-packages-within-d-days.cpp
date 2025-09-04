class Solution {
public:
    bool fn(vector<int>& weights, int days,int mid){
        int load=0,cnt=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid) return false;
            if(load + weights[i]>mid){
                cnt++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        if(cnt<=days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int end=accumulate(weights.begin(),weights.end(),0);
        int start=*max_element(weights.begin(),weights.end());
        int mini;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            bool possible=fn(weights,days,mid);
            if(possible){
                mini=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return mini;

    }
};