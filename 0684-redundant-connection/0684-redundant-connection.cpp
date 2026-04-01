class Disjoint{
    vector<int>par;
    public:
    Disjoint(int n){
        par.resize(n+1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int find(int x){
        if(x==par[x]){
            return x;
        }
        return find(par[par[x]]);
    }
    bool unionop(int x,int y){
        int parx=find(x);
        int pary=find(y);
        if(parx==pary){
            return false;
        }
        par[pary]=parx;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int n=edges.size();
     Disjoint ds(n);
     int j,k;
     for(int i=0;i<n;i++){
       if(ds.unionop(edges[i][0],edges[i][1])==false){
        return {edges[i][0],edges[i][1]};
       }
     }
     return {-1,-1};   
    }
};