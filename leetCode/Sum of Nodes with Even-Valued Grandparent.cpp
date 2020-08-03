// Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

// If there are no nodes with an even-valued grandparent, return 0.

int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
	return root ? sumEvenGrandparent(root->left, root->val, p)
	       + sumEvenGrandparent(root->right, root->val, p)
	       + (gp % 2 ? 0 : root->val)  : 0;
}