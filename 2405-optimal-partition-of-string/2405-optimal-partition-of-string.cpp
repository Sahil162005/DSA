class Solution {
public:
    int partitionString(string s) {
        int l=0,r=0;
        int arr[26]={0};
        int n=s.size();
        int cnt=0;
        while(r<n){
            arr[s[r]-'a']++;
            if(arr[s[r]-'a']>1){
                cnt++;
                fill(begin(arr), end(arr), 0);
                arr[s[r]-'a'] = 1;
            }
            r++;
        }
        return cnt+1;
        
    }
};