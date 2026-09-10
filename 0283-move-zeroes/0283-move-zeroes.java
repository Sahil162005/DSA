class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        for(int i = 0;i<n;i++){
            int ele = nums[i];
            if(ele == 0){
                for(int j = i+1;j<n;j++){
                    if(nums[j]!=0){
                        nums[i] = nums[j];
                        nums[j]=0;
                        break;
                    }
                }
            }
        }
    }
}