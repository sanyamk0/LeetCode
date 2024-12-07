class Solution {
public:
    bool canAchievePenalty(vector<int>& nums, int penalty, int maxOperations) {
        int operationsNeeded = 0;
        for (int balls : nums)
            if (balls > penalty)
                operationsNeeded += (balls - 1) / penalty;
        return operationsNeeded <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *std::max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canAchievePenalty(nums, mid, maxOperations))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};