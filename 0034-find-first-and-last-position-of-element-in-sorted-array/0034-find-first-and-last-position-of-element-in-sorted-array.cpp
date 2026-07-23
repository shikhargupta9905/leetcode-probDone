class Solution {
private:
    int findBound(vector<int>& nums, int target, int low, int high, bool findFirst) {
        // Base case: search space is exhausted
        if (low > high) {
            return -1;
        }

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            if (findFirst) {
                // Check if this is the first occurrence
                if (mid == low || nums[mid - 1] != target) {
                    return mid;
                }
                // Otherwise, keep searching in the left half
                return findBound(nums, target, low, mid - 1, findFirst);
            } else {
                // Check if this is the last occurrence
                if (mid == high || nums[mid + 1] != target) {
                    return mid;
                }
                // Otherwise, keep searching in the right half
                return findBound(nums, target, mid + 1, high, findFirst);
            }
        } else if (nums[mid] < target) {
            return findBound(nums, target, mid + 1, high, findFirst);
        } else {
            return findBound(nums, target, low, mid - 1, findFirst);
        }
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int first = findBound(nums, target, 0, n - 1, true);
        
        // If target doesn't exist at all, no need to look for the last position
        if (first == -1) {
            return {-1, -1};
        }

        int last = findBound(nums, target, 0, n - 1, false);
        return {first, last};
    }
};