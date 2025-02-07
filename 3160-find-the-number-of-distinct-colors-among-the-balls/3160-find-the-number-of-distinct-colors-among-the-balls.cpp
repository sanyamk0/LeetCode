class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> colorMap;
        vector<int> ballArray(limit + 1);
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballArray[ball] != 0) {
                int prevColor = ballArray[ball];
                colorMap[prevColor]--;
                if (colorMap[prevColor] == 0)
                    colorMap.erase(prevColor);
            }
            ballArray[ball] = color;
            colorMap[color]++;
            result[i] = colorMap.size();
        }
        return result;
    }
};