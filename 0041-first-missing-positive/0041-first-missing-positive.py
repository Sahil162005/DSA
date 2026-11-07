class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)
        arr = [1]*n
        
        for i in range (n):
            if(nums[i]<=n and nums[i]>=1):
                arr[nums[i]-1] = 0
        
        for i in range(n):
            if(arr[i]==1):
                return i+1
        
        return n+1
        