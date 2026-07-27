class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n= nums.size();
        // if (n==2){
        //     return nums[n-1]*nums[n-2];
        // }
        sort(nums.begin(),nums.end());
        int i = nums[n-1]-1;
        int j = nums[n-2]-1;
        return i*j;
    }
};