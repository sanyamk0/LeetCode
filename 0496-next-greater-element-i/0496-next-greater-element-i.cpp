class Solution {
private:
    vector<int> nextEl(vector<int> v) {
        int n = v.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < v[i])
                st.pop();
            if (st.empty()) {
                ans[i] = -1;
                st.push(v[i]);
            } else {
                ans[i] = st.top();
                st.push(v[i]);
            }
        }
        return ans;
    }

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size(), m = nums2.size();
        vector<int> ans = nextEl(nums2);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (nums1[i] == nums2[j])
                    v.push_back(ans[j]);
        return v;
    }
};