class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.emplace(0, 0, 0);
        vector<int> directions = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [obstacles, x, y] = pq.top();
            pq.pop();
            if (x == m - 1 && y == n - 1)
                return obstacles;
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i];
                int ny = y + directions[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newObstacles = obstacles + grid[nx][ny];
                    if (newObstacles < dist[nx][ny]) {
                        dist[nx][ny] = newObstacles;
                        pq.emplace(newObstacles, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};