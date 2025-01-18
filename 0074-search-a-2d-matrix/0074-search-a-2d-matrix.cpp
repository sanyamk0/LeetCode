class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        for (int r = 0; r < row; r++) {
            if (matrix[r][0] < target && target < matrix[r][col - 1]) {
                int low = 0, high = col - 1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (target == matrix[r][mid]) {
                        return true;
                    } else if (target < matrix[r][mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};