class Solution {
public:
    int reqDays(vector<int> weights, int cap) {
        int days = 1;
        int sum = 0;
        for (auto it : weights) {
            if (sum + it <= cap) {
                sum += it;
            } else {
                sum = it;
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxC = accumulate(weights.begin(), weights.end(), 0);
        int minC = *max_element(weights.begin(), weights.end());
        int low = minC, high = maxC;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int d = reqDays(weights, mid);
            if (d <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};