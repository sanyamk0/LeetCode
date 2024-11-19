class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        bool found = false;
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> uniqueElements;
            long long currentSum = 0;
            bool valid = true;
            for (int j = i; j < i + k; j++) {
                if (uniqueElements.count(nums[j])) {
                    valid = false;
                    break;
                }
                uniqueElements.insert(nums[j]);
                currentSum += nums[j];
            }
            if (valid) {
                found = true;
                maxSum = max(maxSum, currentSum);
            }
        }
        return found ? maxSum : 0;
    }
};