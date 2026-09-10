class Solution {
    public String reverseWords(String s) {
        Deque<String> st = new ArrayDeque<>();
        int n = s.length();
        String res = "";
        String med="";
        for(int i=0;i<n;i++){
            char ele = s.charAt(i);
            if(ele == ' '){
                if(med.isEmpty()){
                    continue;
                }
                else{
                    st.push(med);
                    med = "";
                }
            }
            else{
                med+=ele;
            }
        }
        if(!med.isEmpty()){
            st.push(med);
        }
        while(!st.isEmpty()){
            res+=st.pop();
            if(!st.isEmpty()){
            res+=" ";
            }
        }
        return res;
    }
}