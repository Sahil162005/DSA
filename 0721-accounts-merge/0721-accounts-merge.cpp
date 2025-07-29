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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    ds.unionbysize(i,mpp[mail]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for (auto it : mpp) {
            string mail = it.first;
            int node = ds.findpar(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            else{
                sort(merged[i].begin(),merged[i].end());
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                for(int j=0;j<merged[i].size();j++){
                    temp.push_back(merged[i][j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;

    }
};