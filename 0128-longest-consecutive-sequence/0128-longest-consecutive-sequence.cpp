class Solution {
public:
    bool ls(int x, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return n;
        sort(nums.begin(), nums.end());
        int maxLen = 1, cnt = 0, last = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 == last) {
                cnt++;
                last = nums[i];
            } else if (nums[i] != last) {
                cnt = 1;
                last = nums[i];
            }
            maxLen = max(maxLen, cnt);
        }
        return maxLen;
    }
};