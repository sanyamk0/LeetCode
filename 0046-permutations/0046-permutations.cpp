class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& ds, vector<int>& mp,
              vector<int>& nums) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!mp[i]) {
                ds.push_back(nums[i]);
                mp[i] = 1;
                func(ans, ds, mp, nums);
                ds.pop_back();
                mp[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> mp(n, 0);
        func(ans, ds, mp, nums);
        return ans;
    }
};