class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (st.find(s[j]) == st.end()) {
                    cnt++;
                    maxi = max(maxi, cnt);
                    st.insert(s[j]);
                } else {
                    break;
                }
            }
        }
        return maxi;
    }
};