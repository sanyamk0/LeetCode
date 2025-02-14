class Solution {
public:
    bool isPossible(int row, int col, char c, vector<vector<char>> board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == c)
                return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isPossible(row, col, c, board)) {
                            board[row][col] = c;
                            if (helper(board) == true) {
                                return true;
                            } else {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { helper(board); }
};