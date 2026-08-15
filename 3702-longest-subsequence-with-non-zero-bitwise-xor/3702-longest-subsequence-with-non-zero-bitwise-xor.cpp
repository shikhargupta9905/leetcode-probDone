class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor=0;
        bool allZero=true;

        for (int num : nums){
            if(num!=0) allZero=false;
            totalXor ^=num;
        }
        if(allZero) return 0;
        return (totalXor!=0)? n : n-1;
    }
};