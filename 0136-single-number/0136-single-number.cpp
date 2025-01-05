class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        return xorr;
    }
};