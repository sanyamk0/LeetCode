class Solution {
public:
    vector<int> preprocessSpecial(const vector<int>& nums) {
        int n = nums.size();
        vector<int> special(n - 1, 0);
        for (int i = 0; i < n - 1; ++i)
            special[i] = (nums[i] % 2) != (nums[i + 1] % 2);
        vector<int> prefixSum(n);
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + special[i - 1];
        return prefixSum;
    }

    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<bool> answer;
        vector<int> prefixSum = preprocessSpecial(nums);
        for (const auto& query : queries) {
            int from = query[0];
            int to = query[1];
            int numSpecialPairs = prefixSum[to] - prefixSum[from];
            int totalPairsInRange = to - from;
            answer.push_back(numSpecialPairs == totalPairsInRange);
        }
        return answer;
    }
};