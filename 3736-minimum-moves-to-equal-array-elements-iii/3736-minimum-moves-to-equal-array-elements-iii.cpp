class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums[nums.size()-1];
        int j =0 , count =0;
        for(int k = 0 ; k < nums.size(); k++){
            int l =abs(nums[k]-i);
            count+=l;
        }
        return count;
    }
};