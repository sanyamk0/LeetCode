class Solution {
public:
    void helper(int i, vector<int> ds, vector<vector<int>>& ans,
                vector<int> nums) {
        if (i >= nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(i + 1, ds, ans, nums);
        ds.pop_back();
        helper(i + 1, ds, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, ds, ans, nums);
        return ans;
    }
};