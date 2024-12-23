/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;
        int totalSwaps = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevelValues;
            vector<int> originalIndices;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelValues.push_back(node->val);
                originalIndices.push_back(i);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            vector<int> sortedValues = currentLevelValues;
            sort(sortedValues.begin(), sortedValues.end());
            vector<int> indexMap(levelSize);
            for (int i = 0; i < levelSize; ++i) {
                indexMap[i] = find(currentLevelValues.begin(),
                                   currentLevelValues.end(), sortedValues[i]) -
                              currentLevelValues.begin();
            }
            vector<bool> visited(levelSize, false);
            for (int i = 0; i < levelSize; ++i) {
                if (visited[i] || indexMap[i] == i)
                    continue;
                int cycleSize = 0, j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = indexMap[j];
                    cycleSize++;
                }
                if (cycleSize > 0)
                    totalSwaps += (cycleSize - 1);
            }
        }
        return totalSwaps;
    }
};