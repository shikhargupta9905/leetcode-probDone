class Solution(object):
    def twoSum(self, nums, target):
        seen ={}
        for i in range (len(nums)):
            rem = target- nums[i]
            if rem in seen :
                return [seen[rem],i] 

            seen[nums[i]]=i
        return -1           

        