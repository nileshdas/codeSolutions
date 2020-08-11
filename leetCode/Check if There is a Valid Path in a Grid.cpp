// Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.


// You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.



// Example 1:


// Input: grid = [[2,4,3],[6,5,2]]
// Output: true
// Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
// Example 2:


// Input: grid = [[1,2,1],[1,2,1]]
// Output: false
// Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
// Example 3:

// Input: grid = [[1,1,2]]
// Output: false
// Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
// Example 4:

// Input: grid = [[1,1,1,1,1,1,3]]
// Output: true
// Example 5:

// Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
// Output: true

class Solution {
public:
    bool dfs(vector<vector<bool>> &g, int i, int j) {
        if (min(i, j) < 0 || i >= g.size() || j >= g[i].size() || !g[i][j])
            return false;
        if (i == g.size() - 2 && j == g[i].size() - 2)
            return true;
        g[i][j] = false;
        return dfs(g, i - 1, j) || dfs(g, i + 1, j) || dfs(g, i, j + 1) || dfs(g, i, j - 1);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> g(m * 3, vector<bool>(n * 3));
        for (auto i = 0; i < m; ++i)
            for (auto j = 0; j < n; ++j) {
                auto r = grid[i][j];
                g[i * 3 + 1][j * 3 + 1] = true;
                g[i * 3 + 1][j * 3 + 0] = r == 1 || r == 3 || r == 5;
                g[i * 3 + 1][j * 3 + 2] = r == 1 || r == 4 || r == 6;
                g[i * 3 + 0][j * 3 + 1] = r == 2 || r == 5 || r == 6;
                g[i * 3 + 2][j * 3 + 1] = r == 2 || r == 3 || r == 4;
            }
        return dfs(g, 1, 1);
    }
};