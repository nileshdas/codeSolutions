// Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

// Recall that:

// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
// The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;https://leetcode.com/discuss/general-discussion/655704/
 *     TreeNode *right;https://leetcode.com/discuss/general-discussion/655704/
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode* lca;
	int maxDepth = 0;
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		helper(root, 0);
		return lca;
	}
	int helper(TreeNode* node, int depth) {
		maxDepth = max(depth, maxDepth);
		if (!node) {
			return depth;
		}
		int left = helper(node->left, depth + 1);
		int right = helper(node->right, depth + 1);
		if (left == maxDepth && right == maxDepth) {
			lca = node;
		}
		return max(left, right);
	}
};