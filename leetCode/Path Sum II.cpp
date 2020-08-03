// 113. Path Sum II
// Medium

// 1836

// 67

// Add to List

// Share
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>>res;
		vector<int>temp;
		helper(root, res, temp, sum);
		return res;
	}
	void helper(TreeNode* node, vector<vector<int>>&res, vector<int>&temp, int sum) {
		if (!node) {
			return;
		}
		temp.push_back(node->val);
		if (!(node->left) && !(node->right) && sum == node->val) {
			res.push_back(temp);
		}
		helper(node->left, res, temp, sum - (node->val));
		helper(node->right, res, temp, sum - (node->val));
		temp.pop_back();

	}

};