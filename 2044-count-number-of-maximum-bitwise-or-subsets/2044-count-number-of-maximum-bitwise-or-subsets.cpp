class Solution {
public:
    void findSubsets(int idx, int currentOr, const vector<int>& nums, int maxOr,
                     int& count) {
        if (idx == nums.size()) {
            if (currentOr == maxOr)
                count++;
            return;
        }
        findSubsets(idx + 1, currentOr | nums[idx], nums, maxOr, count);
        findSubsets(idx + 1, currentOr, nums, maxOr, count);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums)
            maxOr |= num;
        int count = 0;
        findSubsets(0, 0, nums, maxOr, count);
        return count;
    }
};