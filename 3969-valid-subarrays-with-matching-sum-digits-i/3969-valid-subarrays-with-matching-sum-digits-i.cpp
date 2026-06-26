class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt= 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long sum =0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum% 10 !=x)continue;
                string s = to_string(sum);
                if(s[0]-'0' !=x)continue;
                cnt++;
                
            }
        }
        return cnt;
    }
};