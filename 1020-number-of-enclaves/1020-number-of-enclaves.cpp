class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid,
             int m, int n) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
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
                bfs(r, 0, vis, grid, m, n);
            if (grid[r][n - 1] == 1 && !vis[r][n - 1])
                bfs(r, n - 1, vis, grid, m, n);
        }
        for (int c = 0; c < n; c++) {
            if (grid[0][c] == 1 && !vis[0][c])
                bfs(0, c, vis, grid, m, n);
            if (grid[m - 1][c] == 1 && !vis[m - 1][c])
                bfs(m - 1, c, vis, grid, m, n);
        }
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (vis[r][c] == 1)
                    cnt++;
        return totalOnes - cnt;
    }
};