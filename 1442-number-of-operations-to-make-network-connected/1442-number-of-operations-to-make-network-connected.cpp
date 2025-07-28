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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cntextras=0;
        disjoint ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findpar(u)==ds.findpar(v)) cntextras++;
            else{
                ds.unionbysize(u,v);
            }
        }
        int compcnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)compcnt++;
        }
        if(cntextras>=compcnt-1){
            return compcnt-1;
        }
        return -1;
    }
};