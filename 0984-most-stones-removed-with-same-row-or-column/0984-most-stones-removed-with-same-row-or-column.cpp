class disjoint{
public:
vector<int>parent,size;
  disjoint(int n){
    parent.resize(n);
    size.resize(n,1);
    for(int i=0;i<n;i++){
      parent[i]=i;
    }
  }
  int findpar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findpar(parent[node]);
  }
  void unionbysize(int u,int v){
    int upar=findpar(u);
    int vpar=findpar(v);
    if(upar==vpar) return;
    if(size[upar]>size[vpar]){
        parent[vpar]=upar;
        size[upar]+=size[vpar];
    }
    else{
        parent[upar]=vpar;
        size[vpar]+=size[upar];
    }
  }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()==1){
            return 0;
        }
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            int x=it[0];
            int y=it[1];
            maxrow=max(x,maxrow);
            maxcol=max(y,maxcol);
        }
        disjoint ds(maxrow+maxcol+2);
        unordered_map<int,int>mpp;
        for(auto it:stones){
            int x=it[0];
            int y=it[1]+maxrow+1;
            ds.unionbysize(x,y);
            mpp[x]++;
            mpp[y]++;
        }
        int cnt=0;
        for(auto it:mpp){
            if(it.first==ds.findpar(it.first)){
                cnt++;
            }
        }
        return n-cnt;
        
    }
};