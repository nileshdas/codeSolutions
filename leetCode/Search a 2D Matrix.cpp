/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int e = matrix[mid / n][mid % n];
            if (target < e) {
                end = mid - 1;
            } else if (target > e) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};