class Solution {
public:
    bool check(vector<int>& piles, int k, int h) {
        long long total = 0;
        for (auto it : piles)
            total += ceil((double)(it) / (double)(k));
        if (total <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        int ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};