/*

Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.



Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].

 */

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, ret;
        if (root1) dfs(root1, v1);
        if (root2) dfs(root2, v2);
        int pos1 = 0 , pos2 = 0;
        while (pos1 < v1.size() && pos2 < v2.size()) {
            if (v1[pos1] < v2[pos2]) ret.push_back(v1[pos1++]);
            else ret.push_back(v2[pos2++]);
        }
        while (pos1 < v1.size()) ret.push_back(v1[pos1++]);
        while (pos2 < v2.size()) ret.push_back(v2[pos2++]);
        return ret;
    }
    void dfs(TreeNode* root, vector<int>&v) {
        if (root->left) dfs(root->left, v);
        v.push_back(root->val);
        if (root->right) dfs(root->right, v);
    }
};