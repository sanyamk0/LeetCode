class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gSize = g.size(), sSize = s.size();
        int i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < gSize && j < sSize) {
            if (g[i] <= s[j])
                i++;
            j++;
        }
        return i;
    }
};