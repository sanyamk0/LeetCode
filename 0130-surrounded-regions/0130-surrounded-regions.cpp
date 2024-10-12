class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis,
             vector<vector<char>>& board, int m, int n) {
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = r + delRow[i];
            int nCol = c + delCol[i];
            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                !vis[nRow][nCol] && board[nRow][nCol] != 'X') {
                dfs(nRow, nCol, vis, board, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<char>> ans(m, vector<char>(n));
        for (int r = 0; r < m; r++) {
            if (board[r][0] == 'O' && !vis[r][0])
                dfs(r, 0, vis, board, m, n);
            if (board[r][n - 1] == 'O' && !vis[r][n - 1])
                dfs(r, n - 1, vis, board, m, n);
        }
        for (int c = 0; c < n; c++) {
            if (board[0][c] == 'O' && !vis[0][c])
                dfs(0, c, vis, board, m, n);
            if (board[m - 1][c] == 'O' && !vis[m - 1][c])
                dfs(m - 1, c, vis, board, m, n);
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (vis[r][c] == 1)
                    ans[r][c] = 'O';
                else
                    ans[r][c] = 'X';
            }
        }
        board = ans;
    }
};