class Solution {
public:
    void helper(int i, vector<int> ds, vector<vector<int>>& ans,
                vector<int> nums, int target) {
        if (i >= nums.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (nums[i] <= target) {
            ds.push_back(nums[i]);
            helper(i, ds, ans, nums, target - nums[i]);
            ds.pop_back();
        }
        helper(i + 1, ds, ans, nums, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, ds, ans, candidates, target);
        return ans;
    }
};