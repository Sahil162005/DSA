class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        mini = prices[0]
        maxi = 0
        for i in range (1,len(prices)):
            maxi = max(prices[i]-mini,maxi)
            mini = min(prices[i],mini)
        
        return maxi
        