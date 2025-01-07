class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int r = 0; r < n; r++) {
            for (int c = r + 1; c < n; c++) {
                swap(matrix[c][r], matrix[r][c]);
            }
            reverse(matrix[r].begin(), matrix[r].end());
        }
    }
};