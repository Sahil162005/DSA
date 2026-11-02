class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        arr = []
        mpp = {}
        for i in range (len(nums)):
            num = nums[i]
            req = target - num
            if req in mpp :
                arr.append(mpp[req])
                arr.append(i)
                break
            mpp[num] = i
        return arr