// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Example 1:

// Input: [1,3,null,null,2]

//    1
//   /
//  3
//   \
//    2

// Output: [3,1,null,null,2]

//    3
//   /
//  1
//   \
//    2
// Example 2:

// Input: [3,1,4,null,null,2]

//   3
//  / \
// 1   4
//    /
//   2

// Output: [2,1,4,null,null,3]

//   2
//  / \
// 1   4
//    /
//   3
// Follow up:

// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?

class Solution {

public:
	TreeNode *first;
	TreeNode *second;
	TreeNode *prev;
	TreeNode *p;
	void solve(TreeNode *root)
	{
		if (root == NULL)
		{
			return;
		}

		solve(root->left);

		if (prev != NULL)
		{

			if (prev->val > root->val)
			{
				if (first == NULL)
				{
					first = prev;
					p = root;
				}
				else
				{
					second = root;
				}
			}

		}

		prev = root;
		solve(root->right);

	}
	void recoverTree(TreeNode* root) {

		if (root == NULL)
		{
			return;
		}
		first = NULL;
		second = NULL;
		prev = NULL;

		solve(root);
		if (first != NULL)
		{
			if (second != NULL)
			{
				swap(first->val, second->val);
			}
			else
			{
				swap(first->val, p->val);

			}
		}



	}
}; class Solution {

public:
	TreeNode *first;
	TreeNode *second;
	TreeNode *prev;
	TreeNode *p;
	void solve(TreeNode *root)
	{
		if (root == NULL)
		{
			return;
		}

		solve(root->left);

		if (prev != NULL)
		{

			if (prev->val > root->val)
			{
				if (first == NULL)
				{
					first = prev;
					p = root;
				}
				else
				{
					second = root;
				}
			}

		}

		prev = root;
		solve(root->right);

	}
	void recoverTree(TreeNode* root) {

		if (root == NULL)
		{
			return;
		}
		first = NULL;
		second = NULL;
		prev = NULL;

		solve(root);
		if (first != NULL)
		{
			if (second != NULL)
			{
				swap(first->val, second->val);
			}
			else
			{
				swap(first->val, p->val);

			}
		}



	}
};