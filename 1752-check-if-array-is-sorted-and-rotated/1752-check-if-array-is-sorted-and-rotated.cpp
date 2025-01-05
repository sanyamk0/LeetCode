class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++)
            if (nums[i] > nums[i + 1])
                cnt++;
        if (cnt == 0)
            return true;
        else if (cnt == 1 && nums[n - 1] <= nums[0])
            return true;
        else
            return false;
    }
};