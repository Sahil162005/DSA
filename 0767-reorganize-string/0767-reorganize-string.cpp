class Solution {
public:
    string reorganizeString(string s) {
        int n =s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            if(mpp[s[i]]>(n+1)/2){
                return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        for(auto it :mpp){
            pq.push({it.second,it.first});
        }
        string ans ="";
        while(!pq.empty()){
            int freq1 = pq.top().first;
            char l1 = pq.top().second;
            ans+=l1;
            freq1--;
            pq.pop();
            if(!pq.empty()){
                int freq2 = pq.top().first;
                char l2 = pq.top().second;
                pq.pop();
                ans+=l2;
                freq2--;
                if(freq2>0){
                pq.push({freq2,l2});
                }
            }
            if(freq1>0){
                pq.push({freq1,l1});
            }
        }
        return ans;
    }
};