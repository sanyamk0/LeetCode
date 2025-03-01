class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }
        int nonZeroIndex = 0;
        for (int iterateIndex = 0; iterateIndex < n; iterateIndex++)
            if (nums[iterateIndex] != 0)
                nums[nonZeroIndex++] = nums[iterateIndex];
        while (nonZeroIndex < n)
            nums[nonZeroIndex++] = 0;
        return nums;
    }
};