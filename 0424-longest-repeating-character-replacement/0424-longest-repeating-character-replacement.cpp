class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), maxFreq = 0, maxLen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            int diff = r - l + 1 - maxFreq;
            while (diff > k) {
                mp[s[l]]--;
                l++;
                maxFreq = max(maxFreq, mp[s[l]]);
                diff--;
            }
            if (diff <= k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};