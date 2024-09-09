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
    void findParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    TreeNode* findTarget(TreeNode* root, int target) {
        if (!root)
            return nullptr;
        if (root->val == target)
            return root;
        TreeNode* leftResult = findTarget(root->left, target);
        if (leftResult)
            return leftResult;
        TreeNode* rightResult = findTarget(root->right, target);
        return rightResult;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);
        TreeNode* targetNode = findTarget(root, start);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(targetNode);
        vis[targetNode] = true;
        int time = -1;
        while (!q.empty()) {
            int s = q.size();
            time++;
            for (int i = 0; i < s; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if (parent[curr] && !vis[parent[curr]]) {
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
        }
        return time;
    }
};