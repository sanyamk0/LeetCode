class Solution {
public:
    int getLargest(vector<int> nums) {
        int largest = INT_MIN, n = nums.size(), ind = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
                ind = i;
            }
        }
        return ind;
    }
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        for (int i = 0; i < k; i++) {
            int ind = getLargest(nums);
            score += nums[ind];
            nums[ind] = ceil(nums[ind] / 3.0);
        }
        return score;
    }
};