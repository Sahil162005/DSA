class Solution:
    def plusOne(self, nums: list[int]) -> list[int]:
        n = len(nums)
        i = n-1
        carry = 1
        while i>=0 :
            nums[i]+=carry
            carry = 0
            if(nums[i]>9) :
                nums[i] = 0
                carry = 1
            else :
                break
            i-=1
        
        if (carry == 1):
            nums[0] = 1
            nums.append(0)
        return nums