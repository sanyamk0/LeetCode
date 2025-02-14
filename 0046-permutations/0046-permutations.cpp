class Solution {
public:
    void helper(int ind, vector<int> nums, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            swap(nums[i], nums[ind]);
            helper(ind + 1, nums, ans);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};