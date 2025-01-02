class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else
                prefix[i + 1] = prefix[i];
        }
        vector<int> ans;
        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            ans.push_back(prefix[ri + 1] - prefix[li]);
        }
        return ans;
    }
};