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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
    void findMax(TreeNode* root, int& diameter) {
        if (root == NULL)
            return;
        int lh = height(root->left);
        int rh = height(root->right);
        diameter = max(diameter, lh + rh);
        findMax(root->left, diameter);
        findMax(root->right, diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findMax(root, diameter);
        return diameter;
    }
};