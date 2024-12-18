class Solution {
public:
    int dayPoss(vector<int> weights, int cap) {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for (auto it : weights) {
            high += it;
            if (it > low)
                low = it;
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            int daysReq = dayPoss(weights, mid);
            if (daysReq <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};