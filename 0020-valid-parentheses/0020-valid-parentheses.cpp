class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(!st.empty() && ((s[i]==')' && st.top()=='(') || 
                (s[i]=='}' && st.top()=='{')||
                (s[i]==']' && st.top()=='['))){
                    st.pop();
                }
                else{
                    return false;
                }
            }
             
            else{
                st.push(s[i]);
            }
        }
        if(!st.empty())return false;
        return true;
    }
};