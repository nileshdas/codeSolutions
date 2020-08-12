// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:

// Input: nums =
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: nums =
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

class Solution {
public:
    int rows, cols;
    vector<vector<int>>f;
    int dfs(vector<vector<int>>& M, int i, int j) {
        if (f[i][j] > 0) {return f[i][j];}
        int res = 1;
        if (i + 1 < rows && M[i + 1][j]  > M[i][j]) {res = max(res, 1 + dfs(M, i + 1, j));}
        if (i - 1 >= 0   && M[i - 1][j]  > M[i][j]) {res = max(res, 1 + dfs(M, i - 1, j));}
        if (j + 1 < cols && M[i][j + 1]  > M[i][j]) {res = max(res, 1 + dfs(M, i, j + 1));}
        if (j - 1 >= 0 && M[i][j - 1]  > M[i][j]) {res = max(res, 1 + dfs(M, i, j - 1));}
        f[i][j] = res;
        return f[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }
        rows = M.size();
        cols = M[0].size();
        f = vector<vector<int>>(rows, vector<int>(cols, 0));
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res = max (res, dfs(M, i, j));
            }
        }
        return res;

    }
};