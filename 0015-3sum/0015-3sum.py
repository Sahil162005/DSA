class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        arr = []
        nums.sort()
        for i in range (len(nums)-2):
            if (i>0 and nums[i]==nums[i-1]):
                continue
            
            j = i+1
            k = len(nums)-1
            while(j<k):
                target = nums[i]+nums[j]+nums[k]
                if(target > 0):
                    k-=1
                elif(target < 0):
                    j+=1
                else:
                     arr.append([nums[i],nums[j],nums[k]])
                
                     while(j<k and nums[j] == nums[j+1]):
                         j+=1
                     while(j<k and nums[k]==nums[k-1]):
                         k-=1
                     j+=1
                     k-=1

        return arr
            

        
