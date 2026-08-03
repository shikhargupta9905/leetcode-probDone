class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi= 0;
        int n = nums.size();
        vector<int> prefixGcd(n);
        for (int i =0 ; i<nums.size();i++){
            if(nums[i]>maxi){
                maxi= nums[i];
            }
            prefixGcd[i]= std::gcd(nums[i], maxi);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long totalSum=0;
        int l = 0 , r = n-1;
        while (l<r){
            totalSum+=std::gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return totalSum;
    }
};