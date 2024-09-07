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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                int currIdx = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();
                if (i == 0)
                    first = currIdx;
                if (i == size - 1)
                    last = currIdx;
                if (temp->left)
                    q.push({temp->left, (long long)2 * currIdx + 1});
                if (temp->right)
                    q.push({temp->right, (long long)2 * currIdx + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};