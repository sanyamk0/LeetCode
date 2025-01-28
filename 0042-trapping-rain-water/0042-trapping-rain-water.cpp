class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        vector<int> pre(n), suf(n);
        pre[0] = height[0];
        suf[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], height[i]);
        }
        for (int i = 0; i < n; i++) {
            if (height[i] < pre[i] && height[i] < suf[i]) {
                water += min(pre[i], suf[i]) - height[i];
            }
        }
        return water;
    }
};