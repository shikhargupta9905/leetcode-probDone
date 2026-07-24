class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n==1|| nums[0]<nums[n-1]){
            return nums[0];
        }
        int l=0;
        int r = n-2;
        while (l<=r){
            int m = l+(r-l)/2;
            if (nums[m]>nums[m+1]){
                return nums[m+1];
            }
            else if (nums[0]> nums[m]){
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
       return -1;     
    }
};