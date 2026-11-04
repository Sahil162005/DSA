class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        sum = 0
        maxi = -1e5
        for i in range (len(nums)):
            sum+=nums[i]
            maxi = max(maxi,sum)
            if(sum<0):
                sum = 0
            
        
        return maxi