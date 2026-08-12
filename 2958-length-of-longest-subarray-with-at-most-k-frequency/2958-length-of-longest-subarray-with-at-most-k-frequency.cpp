class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n=nums.size();
        int maxLen=0 ; 
        int l=0;
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int r=0; r<n; r++){
           freq[nums[r]]++;
           while(freq[nums[r]]>k){
            freq[nums[l++]]--;
           }
           maxLen= max(maxLen,r-l+1);
    }
    return maxLen;
    }
};