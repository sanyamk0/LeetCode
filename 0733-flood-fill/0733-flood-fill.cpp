class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n));
        q.push({sr, sc});
        vis[sr][sc] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int origCol = image[sr][sc];
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    image[nRow][nCol] == origCol && !vis[nRow][nCol]) {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (vis[r][c]) {
                    ans[r][c] = color;
                } else {
                    ans[r][c] = image[r][c];
                }
            }
        }
        return ans;
    }
};