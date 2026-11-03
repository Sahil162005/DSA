class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        nums.sort()
        n= len(nums)
        if (n == 1):
            return nums[0]
        cnt = 1
        res = 0
        for i in range (1,n):
            if(nums[i]==nums[i-1]):
                cnt+=1
                if (cnt > n/2):
                    res = nums[i]
                    break
            else :
                cnt = 1
        return res