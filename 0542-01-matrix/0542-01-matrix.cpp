class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) {
                    q.push({{r, c}, 0});
                    vis[r][c] = 1;
                }
            }
        }
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[r][c] = dis;
            for (int i = 0; i < 4; i++) {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, dis + 1});
                }
            }
        }
        return ans;
    }
};