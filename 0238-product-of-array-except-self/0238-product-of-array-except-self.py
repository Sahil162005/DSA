class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        pre = [1]*len(nums)
        suf = [1]*len(nums)
        pref = 1
        suff = 1
        ans = [1]*len(nums)
        for i in range (len(nums)):
            pre[i]=pref
            pref*=nums[i]
        for i in range (len(nums)-1,-1,-1):
            suf[i] = suff
            suff*=nums[i]
        
        for i in range(len(nums)):
            ans[i] = pre[i]*suf[i]
        
        return ans