class Solution {
public:
    int helper(int n, vector<int>& nums) {
        int prev = nums[0], prev2 = 0;
        int pick, notPick, curr;
        for (int i = 1; i < n; i++) {
            pick = nums[i];
            if (i > 1)
                pick += prev2;
            notPick = prev;
            curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return helper(n, nums);
    }
};