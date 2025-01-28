class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int maxFishCount = 0;
        function<int(int, int)> depthFirstSearch = [&](int row,
                                                       int col) -> int {
            int fishCount = grid[row][col];
            grid[row][col] = 0;
            int directions[5] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];
                if (newRow >= 0 && newRow < numRows && newCol >= 0 &&
                    newCol < numCols && grid[newRow][newCol] > 0) {
                    fishCount += depthFirstSearch(newRow, newCol);
                }
            }
            return fishCount;
        };
        for (int i = 0; i < numRows; ++i)
            for (int j = 0; j < numCols; ++j)
                if (grid[i][j] > 0)
                    maxFishCount = max(maxFishCount, depthFirstSearch(i, j));
        return maxFishCount;
    }
};