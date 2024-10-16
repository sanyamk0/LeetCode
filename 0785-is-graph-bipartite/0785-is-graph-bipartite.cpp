class Solution {
public:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color,
             int n) {
        color[node] = c;
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (dfs(it, !c, graph, color, n) == false)
                    return false;
            } else if (color[it] == color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
            if (color[i] == -1)
                if (dfs(i, 0, graph, color, n) == false)
                    return false;
        return true;
    }
};