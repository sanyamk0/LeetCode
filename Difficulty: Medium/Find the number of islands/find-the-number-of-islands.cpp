//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const vector<pair<int, int>> directions = {
                                                {-1, -1}, {-1, 0}, {-1, 1},
                                                {0, -1},           {0, 1},
                                                {1, -1}, {1, 0}, {1, 1}
                                               };
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (const auto& dir : directions) {
            int newX = x + dir.first, newY = y + dir.second;
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1')
                dfs(grid, newX, newY);
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends