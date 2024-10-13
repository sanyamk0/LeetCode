class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    q.push({{r, c}, 0});
                    vis[r][c] = 1;
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int time = 0, pushCnt = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 1;
                    pushCnt++;
                }
            }
        }
        return pushCnt == fresh ? time : -1;
    }
};