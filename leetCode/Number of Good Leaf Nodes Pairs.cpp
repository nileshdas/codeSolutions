// Given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.



// Example 1:


// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.

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
	int ans = 0;
	int countPairs(TreeNode* root, int distance) {
		dfs(root, distance);
		return ans;
	}
	vector<int> dfs(TreeNode*root, int d) {
		vector<int> p = {};
		if (root == nullptr) return p;

		auto left = dfs(root->left, d);
		auto right = dfs(root->right, d);

		if (left.size() == 0 && right.size() == 0) {
			p.push_back(1);
			return p;
		}
		for (int i = 0; i < left.size(); i++) {
			for (int j = 0; j < right.size(); j++) {
				if (left[i] + right[j] <= d ) {
					ans ++;
				}
			}
		}
		for (int i = 0; i < left.size(); i++) {
			left[i]++;
			p.push_back(left[i]);
		}

		for (int i = 0; i < right.size(); i++) {
			right[i]++;
			p.push_back(right[i]);
		}

		return p;
	}
};