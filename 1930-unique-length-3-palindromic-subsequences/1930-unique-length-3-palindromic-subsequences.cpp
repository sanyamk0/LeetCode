class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for (int i = 0; i < s.length(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] != first[i]) {
                unordered_set<char> middleChars;
                for (int j = first[i] + 1; j < last[i]; j++)
                    middleChars.insert(s[j]);
                result += middleChars.size();
            }
        }
        return result;
    }
};