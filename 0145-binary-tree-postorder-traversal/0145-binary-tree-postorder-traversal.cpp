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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v;
        vector<int> leftTraversal = postorderTraversal(root->left);
        v.insert(v.end(), leftTraversal.begin(), leftTraversal.end());
        vector<int> rightTraversal = postorderTraversal(root->right);
        v.insert(v.end(), rightTraversal.begin(), rightTraversal.end());
        v.push_back(root->val);
        return v;
    }
};