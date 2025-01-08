class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        return str1.size() <= str2.size() &&
               str2.substr(0, str1.size()) == str1 &&
               str2.substr(str2.size() - str1.size()) == str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isPrefixAndSuffix(words[i], words[j]))
                    count++;
        return count;
    }
};