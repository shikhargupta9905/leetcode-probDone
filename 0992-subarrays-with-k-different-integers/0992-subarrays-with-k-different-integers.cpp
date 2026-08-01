class Solution {
public:
 int atMostK(vector<int> &nums , int k){
        int l =0 , n = nums.size();
        int sum =0;
        int count =0;
        unordered_map <int ,int> freq;
        for(int r=0; r<n;r++){
            freq[nums[r]]++;
            if(freq[nums[r]]==1){
                sum++;
            }
            while(sum>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    sum--;
                }
                l++;
            }
            count+=r-l+1;
        }
        return count;
 }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atMostK(nums, k)- atMostK(nums, k-1);
    }
};