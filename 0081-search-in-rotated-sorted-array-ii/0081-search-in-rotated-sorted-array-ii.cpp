class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        for (auto it : nums) {
            if (it == target)
                return true;
        }
        return false;
    }
};