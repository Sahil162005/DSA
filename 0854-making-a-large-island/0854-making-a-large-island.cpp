class disjoint{
    public:
    vector<int>par,size;
    disjoint(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int findpar(int node){
        if(node==par[node]) return node;
        return par[node]=findpar(par[node]);
    }
    void unionbysize(int u,int v){
        int pu=findpar(u);
        int pv=findpar(v);
        if (pu == pv) return;
        if(size[pu]>size[pv]){
            par[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            par[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjoint ds(n*n);
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        int maxsize=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                else{
                    for(int k=0;k<4;k++){
                        int row=i+drow[k];
                        int col=j+dcol[k];
                        if(row>=0 && row<n && col>=0 && col<n){
                            if(grid[row][col]==1){
                                ds.unionbysize(i*n+j,row*n+col);
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                else{
                    int size=0;
                    set<int>st;
                    for(int k=0;k<4;k++){
                        int row=i+drow[k];
                        int col=j+dcol[k];
                        if(row>=0 && row<n && col>=0 && col<n){
                            if(grid[row][col]==1){
                                st.insert(ds.findpar(row*n+col));
                            }
                        }
                    }
                    for(auto it:st){
                        size+=ds.size[it];
                    }
                    size+=1;
                    maxsize=max(maxsize,size);

                }

            }
        }
        if(maxsize==0){
            return n*n;
        }
        return maxsize;
        
    }
};