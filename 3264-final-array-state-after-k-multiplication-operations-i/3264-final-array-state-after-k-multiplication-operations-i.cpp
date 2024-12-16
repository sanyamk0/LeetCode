class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto [val, index] = pq.top();
            pq.pop();
            val = val * multiplier;
            pq.push({val, index});
        }
        while (!pq.empty()) {
            auto [val, index] = pq.top();
            pq.pop();
            nums[index] = val;
        }
        return nums;
    }
};