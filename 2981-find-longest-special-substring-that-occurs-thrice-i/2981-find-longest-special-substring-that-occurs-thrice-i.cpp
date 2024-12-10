class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count = 1;
            mp[{s[i], count}]++;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == s[j + 1]) {
                    count++;
                    mp[{s[i], count}]++;
                } else
                    break;
            }
        }
        int ans1 = 0;
        for (auto x : mp)
            if (x.second >= 3)
                ans1 = max(x.first.second, ans1);
        return ans1 == 0 ? -1 : ans1;
    }
};