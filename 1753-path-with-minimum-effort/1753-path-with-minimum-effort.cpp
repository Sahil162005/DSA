class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        pq.push({{0,0},0});
        int dcol[]={0,1,0,-1};
        int drow[]={1,0,-1,0};
        while(!pq.empty()){
            int x=pq.top().first.first;
            int y=pq.top().first.second;
            int val=pq.top().second;
            pq.pop();
            for(int k=0;k<4;k++){
                int row=x+drow[k];
                int col=y+dcol[k];
                if(row>=0 && row<m && col>=0 && col<n){
                    int valu=abs(heights[x][y]-heights[row][col]);
                    int diff=max(val,valu);
                    if(dis[row][col]>diff){
                        dis[row][col]=diff;
                        pq.push({{row,col},diff});
                    }
                }
            }


        }
        return dis[m-1][n-1];
    }
};