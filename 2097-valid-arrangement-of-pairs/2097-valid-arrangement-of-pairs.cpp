class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;
        for (const auto& pair : pairs) {
            int start = pair[0];
            int end = pair[1];
            graph[start].push_back(end);
            outDegree[start]++;
            inDegree[end]++;
        }
        int startNode = pairs[0][0];
        for (const auto& pair : pairs) {
            int start = pair[0];
            if (outDegree[start] > inDegree[start]) {
                startNode = start;
                break;
            }
        }
        stack<int> stk;
        vector<vector<int>> result;
        stk.push(startNode);
        while (!stk.empty()) {
            int current = stk.top();
            if (graph[current].empty()) {
                result.push_back({current, current});
                stk.pop();
            } else {
                stk.push(graph[current].back());
                graph[current].pop_back();
            }
        }
        vector<vector<int>> arrangement;
        for (int i = result.size() - 1; i > 0; --i)
            arrangement.push_back({result[i][0], result[i - 1][0]});
        return arrangement;
    }
};