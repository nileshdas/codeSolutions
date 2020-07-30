// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    int helper(TreeNode* root, int &maxt) {
        if (!root) {return 0;}
        int l = helper(root->left, maxt);
        int r = helper(root->right, maxt);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > maxt) maxt = l + r + root->val;
        return root->val += max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int maxt = INT_MIN;
        helper(root, maxt);
        return maxt;
    }
};