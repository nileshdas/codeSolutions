// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level X such that the sum of all the values of nodes at level X is maximal.



// Example 1:



// Input: [1,7,0,7,-8,null,null]
// Output: 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.


// Note:

// The number of nodes in the given tree is between 1 and 10^4.
// -10^5 <= node.val <= 10^5

vector<int> sums;
void dfs(TreeNode* r, size_t lvl) {
    if (r != nullptr) {
        sums.resize(max(sums.size(), lvl));
        sums[lvl - 1] += r->val;
        dfs(r->left, lvl + 1);
        dfs(r->right, lvl + 1);
    }
}
int maxLevelSum(TreeNode* r) {
    dfs(r, 1);
    return distance(begin(sums), max_element(begin(sums), end(sums))) + 1;
}