class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = nums[0];
        int j = nums[n-1];
        return gcd(i,j);
    }
};