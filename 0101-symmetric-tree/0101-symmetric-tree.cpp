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
    bool check(TreeNode* rootL, TreeNode* rootR) {
        if (!rootL || !rootR)
            return rootL == rootR;
        return (rootL->val == rootR->val) && check(rootL->left, rootR->right) &&
               check(rootL->right, rootR->left);
    }
    bool isSymmetric(TreeNode* root) { return check(root->left, root->right); }
};