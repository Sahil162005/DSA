class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                nums[i]=1;
            }
            else{
                nums[i]=-1;
            }
        }
        vector<long long>cnt(2*n+2,0);
        long long bias = n+1;
        long long curr = bias;
        long long pref=0;
        long long total=0;
        cnt[bias]=1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                pref+=cnt[curr];
                curr++;
            }
            else{
                curr--;
                pref-=cnt[curr];
            }
            total += pref;
            cnt[curr]++;
        }
        return total;

    }
};