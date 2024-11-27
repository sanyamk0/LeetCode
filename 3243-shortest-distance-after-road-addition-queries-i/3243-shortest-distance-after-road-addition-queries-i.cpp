class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        vector<int> answer;
        for (int i = 0; i < n - 1; ++i)
            graph[i].push_back(i + 1);
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back(v);
            vector<int> dist(n, numeric_limits<int>::max());
            dist[0] = 0;
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (dist[node] + 1 < dist[neighbor]) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }
            answer.push_back(
                dist[n - 1] == numeric_limits<int>::max() ? -1 : dist[n - 1]);
        }
        return answer;
    }
};