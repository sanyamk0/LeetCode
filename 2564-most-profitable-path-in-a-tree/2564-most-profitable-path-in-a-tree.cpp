class Solution {
public:
    bool dfs(int u, vector<bool>& visited, vector<vector<int>>& adj,
             vector<int>& path) {
        visited[u] = true;
        if (u == 0)
            return true;
        for (int v : adj[u]) {
            if (!visited[v] && dfs(v, visited, adj, path)) {
                path.push_back(v);
                return true;
            }
        }
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        amount[bob] = 0;
        vector<int> bobPath;
        dfs(bob, visited, adj, bobPath);
        reverse(bobPath.begin(), bobPath.end());
        visited.assign(n, false);
        queue<pair<int, int>> q;
        q.push({0, amount[0]});
        visited[0] = true;
        int bobIndex = 0, result = INT_MIN;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [u, curr] = q.front();
                q.pop();
                bool isLeaf = true;
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        if (isLeaf)
                            isLeaf = false;
                        if (bobIndex < bobPath.size() &&
                            v == bobPath[bobIndex]) {
                            amount[v] /= 2;
                        }
                        q.push({v, curr + amount[v]});
                    }
                }
                if (isLeaf)
                    result = max(result, curr);
            }
            if (bobIndex < bobPath.size())
                amount[bobPath[bobIndex]] = 0;
            bobIndex++;
        }
        return result;
    }
};