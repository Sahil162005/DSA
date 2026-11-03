class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        i = len(nums1) -1
        j = m-1
        k = n-1
        while j>=0 and k>=0 :
            if (nums1[j]>=nums2[k]):
                 nums1[i] = nums1[j]
                 j-=1
                 i-=1
            else :
                nums1[i] = nums2[k]
                k-=1
                i-=1
        
        while k>=0 :
            nums1[i] = nums2[k]
            k-=1
            i-=1
        