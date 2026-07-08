class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        water =0
        # lmax= [0]*n
        # rmax= [0]*n

        # lmax[0]= height[0]
        # for i in range (1,n):
        #     lmax[i]= max(lmax[i-1],height[i]) 
        # rmax[n-1]= height[n-1]
        # for i in range (n-2,-1,-1):
        #     rmax[i]= max(rmax[i+1],height[i])
        # water =0
        # for i in range (n):
        #     water +=min(lmax[i],rmax[i])-height[i]
        # return water    


        # 2 pointer 
        
        if not height:
            return 0 
        l , r =0, n-1
        lmax , rmax =0,0
        while l < r :
            if height[l]<height[r]:
                lmax= max(lmax , height[l])
                water +=lmax-height[l]
                l +=1
            else:
                rmax = max(rmax,height[r])
                water +=rmax-height[r]
                r-=1
        return water             
         


            