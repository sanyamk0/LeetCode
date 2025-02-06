class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> productCount;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long product = (long long)nums[i] * nums[j];
                productCount[product]++;
            }
        }
        for (auto const& [product, cnt] : productCount) {
            count += cnt * (cnt - 1) * 4;
        }
        return count;
    }
};