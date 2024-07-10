class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), cnt = 0, preSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            cnt += mp[preSum - goal];
            mp[preSum]++;
        }
        return cnt;
    }
};