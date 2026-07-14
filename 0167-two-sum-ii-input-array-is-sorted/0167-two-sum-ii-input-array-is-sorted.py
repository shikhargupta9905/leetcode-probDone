class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        start = 0 
        n =numbers
        end =len(n)-1

        while start < end:
            t = n[start]+n[end]
            if t == target :
                return [start+1, end+1]

            elif t < target :
                start+=1
            else: 
                end -=1
        return [-1,-1]                
