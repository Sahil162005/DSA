class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if((tokens[i]!="+") && (tokens[i]!="-") &&(tokens[i]!="*")&& (tokens[i]!="/" )){
                int num=stoi(tokens[i]);
                st.push(num);
            }
            else{
                int val1=st.top();
                st.pop();
                int val2=st.top();
                int val3;
                st.pop();
                if(tokens[i]=="+"){
                    val3=val1+val2;
                }
                else if(tokens[i]=="-"){
                    val3=val2-val1;
                }
                else if(tokens[i]=="*"){
                    val3=val2*val1;
                }
                else{
                    val3=val2/val1;
                }
                st.push(val3);
            }
        }
        return st.top();
    }
};