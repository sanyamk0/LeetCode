class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, pushVal = 1, keyCount = 0;
        vector<int> v(26);
        for (auto it : word) // Store char frequency
            v[it - 'a']++;
        sort(v.rbegin(), v.rend()); // Sort stored frequencies
        for (auto it : v) {
            if (it == 0)
                break;
            ans += it * pushVal;
            keyCount++;
            if (keyCount % 8 == 0)
                pushVal++;
        }
        return ans;
    }
};