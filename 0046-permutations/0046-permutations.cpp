class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> ds, vector<int> nums,
                vector<int>& mp) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mp[i] != 1) {
                ds.push_back(nums[i]);
                mp[i] = 1;
                helper(ans, ds, nums, mp);
                ds.pop_back();
                mp[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> mp(nums.size(), 0);
        helper(ans, ds, nums, mp);
        return ans;
    }
};