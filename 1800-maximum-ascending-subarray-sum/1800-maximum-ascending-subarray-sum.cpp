class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxSum = 0;
        int currentSum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        maxSum = max(maxSum, currentSum);
        return maxSum;
    }
};