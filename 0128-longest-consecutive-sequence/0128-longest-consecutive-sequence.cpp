class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>st;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       }
       int cnt=0;
       int maxi=0;
       for(auto num:st){
        if(st.find(num-1)==st.end()){
            cnt=1;
            int val=num;
            while(st.find(val+1)!=st.end()){
                cnt++;
                val++;
            }
        }
        maxi=max(maxi,cnt);

       }
       return maxi;
    }
};