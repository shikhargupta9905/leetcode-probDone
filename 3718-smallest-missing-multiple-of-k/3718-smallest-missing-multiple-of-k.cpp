class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int multiple = k;
    for(int num:nums){
        if(num==multiple){
            multiple+=k;
        }
    }
    return multiple;
    }
};