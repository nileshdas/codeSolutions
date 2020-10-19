/*

In a N x N grid representing a field of cherries, each cell is one of three possible integers.



0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.


Your task is to collect maximum number of cherries possible by following the rules below:



Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.




Example 1:

Input: grid =
[[0, 1, -1],
 [1, 0, -1],
 [1, 1,  1]]
Output: 5
Explanation:
The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.


Note:

grid is an N by N 2D array, with 1 <= N <= 50.
Each grid[i][j] is an integer in the set {-1, 0, 1}.
It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.


 */

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];
        for (int k = 1, maxK = 2 * N - 2; k <= maxK; ++k) {
            for (int i = min(N - 1, k); i >= 0; --i) {
                if (k - i >= N) continue;
                for (int j = min(N - 1, k); j >= 0; --j) {
                    if (k - j >= N || grid[i][k - i] < 0 || grid[j][k - j] < 0) {
                        dp[i][j] = -1;
                        continue;
                    }
                    int cherris = dp[i][j];
                    if (i > 0)  cherris = max(cherris, dp[i - 1][j]);
                    if (j > 0)  cherris = max(cherris, dp[i][j - 1]);
                    if (i > 0 && j > 0)  cherris = max(cherris, dp[i - 1][j - 1]);
                    if (cherris < 0)    continue;
                    dp[i][j] =  cherris + grid[i][k - i];
                    if (i != j) dp[i][j] += grid[j][k - j];
                }
            }
        }
        return max(0, dp[N - 1][N - 1]);
    }
};