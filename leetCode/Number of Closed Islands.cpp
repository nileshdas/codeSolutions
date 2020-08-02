// Share
// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.



// Example 1:



// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation:
// Islands in gray are closed because they are completely surrounded by water (group of 1s).

class Solution {
public:
	int closedIsland(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0) {
					res += dfs(grid, i, j) ? 1 : 0;
				}
			}
		}
		return res;
	}
	bool dfs(vector<vector<int>>&grid, int i, int j) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
			return false;
		}
		if (grid[i][j] == 1) {
			return true;
		}
		grid[i][j] = 1;
		bool d1 = dfs(grid, i + 1, j);
		bool d2 = dfs(grid, i, j + 1);
		bool d3 = dfs(grid, i - 1, j);
		bool d4 = dfs(grid, i, j - 1);
		return d1 && d2 && d3 && d4;



	}
};