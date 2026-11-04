class Solution:
    def maxArea(self, height: list[int]) -> int:
        cur = 0
        maxi = 0
        i = 0
        j = len(height)-1
        while(i<j):
            cur = (j-i)*min(height[i],height[j])
            maxi = max(maxi,cur)
            if(height[i]<=height[j]):
                i+=1
            else :
                j-=1
        
        return maxi
        