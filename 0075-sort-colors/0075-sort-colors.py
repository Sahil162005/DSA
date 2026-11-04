class Solution:
    def sortColors(self, nums: list[int]) -> None:
        l = 0
        for i in range (len(nums)):
            if(nums[i]==0):
                nums[i],nums[l] = nums[l],nums[i]
                l+=1
        
        r = len(nums)-1
        i=r
        while(i>=0):
            if(nums[i]==2):
                nums[i],nums[r] = nums[r],nums[i]
                r-=1
            i-=1