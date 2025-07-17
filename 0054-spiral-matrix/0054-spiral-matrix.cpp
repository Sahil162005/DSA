class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>arr;
        int m=matrix.size();
        int n=matrix[0].size();
        int firstcol=0;
        int firstrow=0;
        int lastcol=n-1;
        int lastrow=m-1;
        while(firstrow <= lastrow && firstcol <= lastcol){
            for(int i=firstcol;i<=lastcol;i++){
                arr.push_back(matrix[firstrow][i]);
            }
            firstrow++;
            for(int i=firstrow;i<=lastrow;i++){
                arr.push_back(matrix[i][lastcol]);
            }
            lastcol--;
            if(firstrow<=lastrow){
            for(int i=lastcol;i>=firstcol;i--){
                arr.push_back(matrix[lastrow][i]);
            }
            }
            lastrow--;
            if(firstcol<=lastcol){
            for(int i=lastrow;i>=firstrow;i--){
                arr.push_back(matrix[i][firstcol]);
            }
            }
            firstcol++;
        }
        return arr;

    }
};