class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>> adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, vis, adj);
        }
    }
    vector<vector<int>> adjacencyList(vector<vector<int>> isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        return adj;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0, n = isConnected.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj = adjacencyList(isConnected);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                provinces++;
            }
        }
        return provinces;
    }
};