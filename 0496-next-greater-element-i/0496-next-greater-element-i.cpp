class Solution {
public:
    unordered_map<int, int> solve(vector<int>& v) {
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < v[i])
                st.pop();
            if (st.empty())
                mp[v[i]] = -1;
            else
                mp[v[i]] = st.top();
            st.push(v[i]);
        }
        return mp;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mp = solve(nums2);
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j])
                    ans.push_back(mp[nums2[j]]);
            }
        }
        return ans;
    }
};