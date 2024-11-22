class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        using Bitset = vector<bool>;
        unordered_map<Bitset, int> count;
        int maxCount = 0;
        for (int i = 0; i < m; i++) {
            Bitset row{matrix[i].begin(), matrix[i].end()};
            if (row[0])
                row.flip();
            maxCount = max(maxCount, ++count[row]);
        }
        return maxCount;
    }
};