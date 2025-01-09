class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        sort(nums.begin(), nums.end());
        return mp[nums[n - 1]];
    }
};