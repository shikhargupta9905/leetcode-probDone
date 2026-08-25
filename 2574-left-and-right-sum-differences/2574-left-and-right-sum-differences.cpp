class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum=0;
        for(int num:nums){
            rsum+=num;
        }
        int lsum=0;
        vector<int> ans(nums.size());

        for(int i =0 ; i< nums.size();i++){
            rsum-=nums[i];
            ans[i]=abs(lsum -rsum);
            lsum+=nums[i];
        }
        return ans;
    }
};