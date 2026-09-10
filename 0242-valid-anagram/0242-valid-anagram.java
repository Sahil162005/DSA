class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        if(s.length()!=t.length()){
            return false;
        }
        Map<Character,Integer> mpp = new HashMap<>();
        for(int i = 0;i<n;i++){
            mpp.put(s.charAt(i),mpp.getOrDefault(s.charAt(i),0)+1);
        }
        for(int i =0;i<n;i++){
            char ele = t.charAt(i);
            if(mpp.containsKey(ele)){
                if(mpp.get(ele) == 1){
                    mpp.remove(ele);
                }
                else{
                    mpp.put(ele,mpp.get(ele)-1);
                }
            }
            else{
                return false;
            }
        }
        if(!mpp.isEmpty()){
            return false;
        }

        return true;
    }
}