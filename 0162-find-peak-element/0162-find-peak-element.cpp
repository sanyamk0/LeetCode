class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= maxi) {
                index = i;
                maxi = nums[i];
            }
        }
        return index;
    }
};