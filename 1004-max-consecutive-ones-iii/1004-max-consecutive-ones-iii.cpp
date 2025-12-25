class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        if(k==0){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]==1) cnt++;
                else{
                    cnt=0;
                }
                maxlen=max(cnt,maxlen);
            }
        }
        else{
            queue<int>q;
        int r=0,l=0;
        while(r<n){
            if(nums[r]==0 && q.size()<k){
                q.push(r);
                
            }
            else if(nums[r]==0 && q.size()==k){
                    l=q.front()+1;
                    q.pop();
                    q.push(r);
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        }
        return maxlen;
    }
};