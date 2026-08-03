class Solution {
public:
int Gcd(int a , int b ){
    while (b!=0){
        int temp =b;
        b=a%b;
        a= temp;
    }
    return a ;
}
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = nums[0];
        int j = nums[n-1];
        return Gcd(i,j);
    }
};