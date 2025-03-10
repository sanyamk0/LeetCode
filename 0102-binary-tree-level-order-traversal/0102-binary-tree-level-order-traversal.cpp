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
    void bfs(TreeNode* root, vector<vector<int>>& ans) {
        if (root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
};