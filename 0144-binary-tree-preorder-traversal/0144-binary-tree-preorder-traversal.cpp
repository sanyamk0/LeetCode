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
    void preOrder(TreeNode* node, vector<int>& v) {
        if (!node)
            return;
        v.push_back(node->val);
        preOrder(node->left, v);
        preOrder(node->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preOrder(root, v);
        return v;
    }
};