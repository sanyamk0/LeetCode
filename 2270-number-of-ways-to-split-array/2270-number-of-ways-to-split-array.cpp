class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        long long totalSum = 0;
        for (int num : nums)
            totalSum += num;
        long long leftSum = 0;
        int validSplits = 0;
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum)
                validSplits++;
        }
        return validSplits;
    }
};