/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, vector<TreeNode*>& v, TreeNode* x) {
        if (!root)
            return false;
        v.push_back(root);
        if (root == x)
            return true;
        if (path(root->left, v, x) || path(root->right, v, x))
            return true;
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b;
        path(root, a, p);
        path(root, b, q);
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i])
            i++;
        return a[i - 1];
    }
};