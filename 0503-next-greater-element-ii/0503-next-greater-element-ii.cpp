class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;
            while (!st.empty() && st.top() <= nums[index])
                st.pop();
            if (st.empty())
                nge[index] = -1;
            else
                nge[index] = st.top();
            st.push(nums[index]);
        }
        return nge;
    }
};