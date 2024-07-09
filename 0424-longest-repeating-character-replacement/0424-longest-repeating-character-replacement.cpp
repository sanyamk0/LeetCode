class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), maxFreq = 0, maxLen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            if (r - l + 1 - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }
            if (r - l + 1 - maxFreq <= k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};