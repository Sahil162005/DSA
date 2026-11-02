class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        n = 0
        for i in range (len(nums)):
            if(nums[i]!=0):
                n+=1
        
        cnt = 0
        for i in range (len(nums)):
            if(nums[i]!=0):
                nums[i],nums[cnt] = nums[cnt],nums[i]
                cnt+=1
                if (cnt == n) :
                    break
        
        
        