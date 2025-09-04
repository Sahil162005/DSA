class Solution {
public:
    bool fn(vector<int>& bloomDay, int m, int k,int mid){
        int cnt=0;
        int res=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                res++;
                if(res==m)return true;
                cnt=0;
            }
            
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())return -1;
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        int mini=-1;
        while(start<=end){
            mid=(start+end)/2;
            bool possible=fn(bloomDay,m,k,mid);
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