class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int left = 0;
        int maxi = 0;
        Map<Character, Integer> mpp = new HashMap<>();
        for(int i =0;i<n;i++){
            if(mpp.containsKey(s.charAt(i))){
                while(s.charAt(left)!=s.charAt(i)){
                        mpp.remove(s.charAt(left));
                       left++;
                }
                mpp.remove(s.charAt(left));
                left++;
            }
            mpp.put(s.charAt(i), mpp.getOrDefault(s.charAt(i), 0) + 1);
            maxi = Math.max(maxi,i-left+1);
        }
        return maxi;
    }
}