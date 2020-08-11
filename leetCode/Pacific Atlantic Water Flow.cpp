// /Share
// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:

// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.


// Example:

// Given the following 5x5 matrix:

//   Pacific ~   ~   ~   ~   ~
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic

// Return:

// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> visited;
    void dfs(int i, int j, vector<vector<int>>& matrix, int pre, int label) {
        if (i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix[0].size() - 1 || matrix[i][j] < pre || visited[i][j] == 3 || visited[i][j] == label)
            return;
        visited[i][j] += label;
        if (visited[i][j] == 3) res.push_back({i, j});
        dfs(i + 1, j, matrix, matrix[i][j], label);
        dfs(i - 1, j, matrix, matrix[i][j], label);
        dfs(i, j + 1, matrix, matrix[i][j], label);
        dfs(i, j - 1, matrix, matrix[i][j], label);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        visited.resize(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dfs(0, j, matrix, INT_MIN, 1);
            dfs(m - 1, j, matrix, INT_MIN, 2);
        }

        for (int i = 0; i < m; i++) {
            dfs(i, 0, matrix, INT_MIN, 1);
            dfs(i, n - 1, matrix, INT_MIN, 2);
        }
        return res;
    }
};