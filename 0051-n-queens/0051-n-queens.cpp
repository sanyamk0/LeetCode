class Solution {
public:
    void helper(int col, vector<vector<string>>& ans, vector<string> board,
                vector<int> leftRow, vector<int> lowerDiagonal,
                vector<int> upperDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                helper(col + 1, ans, board, leftRow, lowerDiagonal,
                       upperDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> leftRow(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        helper(0, ans, board, leftRow, lowerDiagonal, upperDiagonal, n);
        return ans;
    }
};