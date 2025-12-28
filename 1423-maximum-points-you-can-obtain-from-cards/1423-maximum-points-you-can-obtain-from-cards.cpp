class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0,r=n-1;
        int lsum=0,rsum=0,maxsum=0;
        while(l<k){
            lsum+=cardPoints[l];
            l++;
        }
        l--;
        maxsum=lsum;
        while(k>0){
            lsum-=cardPoints[l];
            rsum+=cardPoints[r];
            maxsum=max(maxsum,lsum+rsum);
            l--;
            r--;
            k--;
        }
        return maxsum;
    }
};