class Solution {
public:
int Gcd(int i , int j ){
    if (j==0) return i;
    return Gcd(j, i%j);
}
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = nums[0];
        int j = nums[n-1];
        return Gcd(i,j);
    }
};