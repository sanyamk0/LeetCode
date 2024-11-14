class Solution {
private:
    bool canDistribute(const vector<int>& quantities, int n, int maxProducts) {
        int totalStores = 0;
        for (int quantity : quantities) {
            totalStores += quantity / maxProducts;
            if (quantity % maxProducts > 0)
                totalStores++;
        }
        return totalStores <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(quantities, n, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};