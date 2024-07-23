class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v,
               int i) {
        if (i >= nums.size()) {
            ans.push_back(v);
            return;
        }
        // Take
        v.push_back(nums[i]);
        solve(nums, ans, v, i + 1);
        // Not Take
        v.pop_back();
        solve(nums, ans, v, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums, ans, v, 0);
        return ans;
    }
};