class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& graph) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, graph))
                    return true;
            } else if (pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0), pathVis(n, 0);
        for (int i = 0; i < n; i++) {
            if (dfs(i, vis, pathVis, graph) == false)
                ans.push_back(i);
        }
        return ans;
    }
};