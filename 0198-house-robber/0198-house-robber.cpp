class Solution {
public:
    int helper(int n, vector<int>& nums, vector<int>& dp) {
        dp[0] = nums[0];
        int pick, notPick;
        for (int i = 1; i <= n; i++) {
            pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        return helper(n - 1, nums, dp);
    }
};