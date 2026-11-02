class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        n = len(nums)
        arr = []
        sum = 0
        for i in range (n):
            sum+=nums[i]
            arr.append(sum)
    
        return arr