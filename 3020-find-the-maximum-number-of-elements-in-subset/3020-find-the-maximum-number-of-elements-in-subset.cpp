class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxi = 1;
        if(mpp.find(1)!=mpp.end()){
                if(mpp[1]%2!=0){
                    maxi = max(maxi,mpp[1]);
                }
                else{
                    maxi = max(maxi,mpp[1]-1);
            }
            mpp[1]=0;
        }
        for(auto it :mpp){
            if(it.first==1)continue;
            long long k = it.first;
            int curr=0;
            while(mpp.count(k) && mpp[k]>=2){
                curr+=2;
                if (k > 100000) {
                    k = -1; 
                    break;
                }
                k = k * k;
            }
            if(k!=-1 && mpp.count(k) && mpp[k]>=1){
                curr+=1;
            }
            else{
                curr-=1;
            }
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};