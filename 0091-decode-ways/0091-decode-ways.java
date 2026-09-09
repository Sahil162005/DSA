class Solution {
    static int fn(String s,int ind,int []dp){
        if(ind == s.length()){
            return 1;
        }
        if(dp[ind]!= -1){
            return dp[ind];
        }
        int one = 0;
        char curr = s.charAt(ind);
        if(curr == '0'){
            return 0;
        }
        one =fn(s,ind+1,dp);
        if(ind+1<=s.length()-1){
             String res = ""+ curr;
             res+=s.charAt(ind+1);
             if(Integer.parseInt(res)<27){
                one += fn(s,ind+2,dp); 
             }
        }
        return dp[ind] = one;
    }
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        Arrays.fill(dp,-1);
        return fn(s,0,dp);
    }
}