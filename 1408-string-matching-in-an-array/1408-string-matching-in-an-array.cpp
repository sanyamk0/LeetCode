class Solution {
public:
    bool isContained(const string& small, const string& large) {
        return large.find(small) != string::npos;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (isContained(words[i], words[j])) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};