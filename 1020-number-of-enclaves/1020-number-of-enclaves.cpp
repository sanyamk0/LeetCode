class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid,
             int m, int n) {
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = r + delRow[i];
            int nCol = c + delCol[i];
            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, vis, grid, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int totalOnes = 0, cnt = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (grid[r][c] == 1)
                    totalOnes++;
        for (int r = 0; r < m; r++) {
            if (grid[r][0] == 1 && !vis[r][0])
                dfs(r, 0, vis, grid, m, n);
            if (grid[r][n - 1] == 1 && !vis[r][n - 1])
                dfs(r, n - 1, vis, grid, m, n);
        }
        for (int c = 0; c < n; c++) {
            if (grid[0][c] == 1 && !vis[0][c])
                dfs(0, c, vis, grid, m, n);
            if (grid[m - 1][c] == 1 && !vis[m - 1][c])
                dfs(m - 1, c, vis, grid, m, n);
        }
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (vis[r][c] == 1)
                    cnt++;
        return totalOnes - cnt;
    }
};