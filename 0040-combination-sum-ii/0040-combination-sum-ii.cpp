class Solution {
public:
    void helper(int i, vector<int> ds, set<vector<int>>& ans, vector<int> nums,
                int target) {
        if (i >= nums.size()) {
            if (target == 0) {
                ans.insert(ds);
            }
            return;
        }
        if (nums[i] <= target) {
            ds.push_back(nums[i]);
            helper(i + 1, ds, ans, nums, target - nums[i]);
            ds.pop_back();
        }
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        helper(i + 1, ds, ans, nums, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, ds, st, candidates, target);
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};