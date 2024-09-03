class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (mp.find(s[j]) == mp.end()) {
                    cnt++;
                    maxi = max(maxi, cnt);
                    mp[s[j]] = j;
                } else {
                    break;
                }
            }
        }
        return maxi;
    }
};