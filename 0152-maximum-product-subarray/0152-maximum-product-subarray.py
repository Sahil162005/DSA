class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        n = len(nums)
        pre = 1
        suf = 1
        maxi = nums[0]
        for i in range (n):
            if(pre==0):
                pre=1
            elif (suf==0):
                    suf=1
            pre = pre*nums[i]
            suf = suf*nums[n-i-1]
            maxi= max(maxi,pre,suf)
        
        return maxi

        