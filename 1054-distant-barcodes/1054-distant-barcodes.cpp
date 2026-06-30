class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        vector<int>arr;
        while(!pq.empty()){
            int freq1 = pq.top().first;
            int num1 = pq.top().second;
            pq.pop();
            freq1--;
            arr.push_back(num1);
            if(!pq.empty()){
                int freq2 = pq.top().first;
                int num2 = pq.top().second;
                freq2--;
                pq.pop();
                arr.push_back(num2);
                if(freq2>0){
                    pq.push({freq2,num2});
                }
            }
            if(freq1>0){
                pq.push({freq1,num1});
            }
        }
        return arr;
    }
};