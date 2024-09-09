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
    void preOrder(TreeNode* root, int& nodes) {
        if (!root)
            return;
        nodes++;
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int nodes = 0;
        preOrder(root, nodes);
        return nodes;
    }
};