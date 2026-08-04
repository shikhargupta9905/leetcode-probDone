class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res;
        for(int i =1 ; i<n ;i++){
            for(int v = nums[i-1]+1;v<nums[i];v++){
                res.push_back(v);
            }
        }
        return res;
    }
};