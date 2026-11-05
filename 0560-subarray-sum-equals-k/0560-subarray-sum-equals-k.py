class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mpp = {0:1}
        pre = 0
        cnt = 0
        for i in range (len(nums)):
             pre+=nums[i]
             target = pre - k
             if target in mpp:
                 cnt+=mpp[target]
            
             mpp[pre] = mpp.get(pre,0)+1
        return cnt

        