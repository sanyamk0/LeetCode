class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int cnt = 0;
        int maxi = 0;
        unordered_set<char> st;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (st.find(s[r]) != st.end()) {
                while (l < r && st.find(s[r]) != st.end()) {
                    st.erase(s[l]);
                    l++;
                    cnt--;
                }
            }
            cnt++;
            maxi = max(maxi, cnt);
            st.insert(s[r]);
        }
        return maxi;
    }
};