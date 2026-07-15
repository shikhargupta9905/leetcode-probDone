class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left=0
        res=0
        for r in range(len(nums)):
            if nums[r]==0:
                left= r+1
            else:
                res= max(res,r-left+1)    
        
        return res                
