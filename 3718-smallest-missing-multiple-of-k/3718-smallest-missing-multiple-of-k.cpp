class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    int max_val=0;
    for(int num:nums) max_val= max(max_val, num);

    vector<bool>present(max_val+1,false);
    for(int num: nums) present[num]=true;

    int multiple=k;
    while(multiple<=max_val && present[multiple]){
        multiple+=k;
    }
    return multiple;
    }
};