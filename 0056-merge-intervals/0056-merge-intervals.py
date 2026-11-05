class Solution:
    def merge(self, nums: list[list[int]]) -> list[list[int]]:
        if (len(nums)==0):
            return []
        arr = []
        nums.sort()
        i = 0
        while i < len(nums):
            start = nums[i][0]
            last = nums[i][1]
            j = i+1 
            while(j<len(nums) and nums[j][0] <= last):
                last = max(last,nums[j][1])
                j+=1
            arr.append([start,last])
            i = j
        
        return arr