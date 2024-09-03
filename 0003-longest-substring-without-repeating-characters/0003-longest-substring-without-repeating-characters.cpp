class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        unordered_map<char, int> mp;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(l, mp[s[r]] + 1);
            }
            maxi = max(maxi, r - l + 1);
            mp[s[r]] = r;
        }
        return maxi;
    }
};