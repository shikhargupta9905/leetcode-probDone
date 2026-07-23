class Solution {
public:
    int findBound(vector<int>& nums, int target, bool findFirst) {
        int low = 0, high = nums.size() - 1;
        int bound = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                bound = mid;
                if (findFirst) {
                    high = mid - 1; // Keep searching left for first occurrence
                } else {
                    low = mid + 1;  // Keep searching right for last occurrence
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return bound;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        
        // If the element doesn't exist, no need to search for the last position
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = findBound(nums, target, false);
        return {first, last};
    }
};