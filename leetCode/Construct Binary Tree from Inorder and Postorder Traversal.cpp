// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return constTree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
private:
    TreeNode* constTree(vector<int>inorder, vector<int>postorder, int start, int end, int index) {
        if (start > end) {return NULL;}
        TreeNode *root = new TreeNode(postorder[index]);

        int inRootIndex = start;
        while (postorder[index] != inorder[inRootIndex]) {
            inRootIndex++;
        }
        root->right = constTree(inorder, postorder, inRootIndex + 1, end, index - 1);
        root->left = constTree(inorder, postorder,  start, inRootIndex - 1, index - (end - inRootIndex) - 1);
        return root;
    }
};