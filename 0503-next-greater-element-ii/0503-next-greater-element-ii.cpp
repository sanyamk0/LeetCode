class Solution {
public:
    vector<int> nextEl(vector<int> v) {
        int n = v.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= v[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(v[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        for (auto it : nums)
            v.push_back(it);
        vector<int> temp = nextEl(v);
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = temp[i];
        return ans;
    }
};