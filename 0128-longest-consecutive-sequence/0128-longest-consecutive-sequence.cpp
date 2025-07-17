class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //    unordered_set<int>st;
    //    for(int i=0;i<nums.size();i++){
    //     st.insert(nums[i]);
    //    }
    //    int cnt=0;
    //    int maxi=0;
    //    for(auto num:st){
    //     if(st.find(num-1)==st.end()){
    //         cnt=1;
    //         int val=num;
    //         while(st.find(val+1)!=st.end()){
    //             cnt++;
    //             val++;
    //         }
    //     }
    //     maxi=max(maxi,cnt);

    //    }
    //    return maxi;
    // }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
       sort(nums.begin(),nums.end());
       int cnt=1;
       int maxi=1;
       for(int i=0;i<nums.size()-1;i++){
        if(nums[i]+1==nums[i+1]){
            cnt++;
        }
        else if(nums[i]==nums[i+1]){
            cnt=cnt;
        }
        else{
            cnt=1;
        }
        maxi=max(cnt,maxi);
       }
       return maxi;
    }
};