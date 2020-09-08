/*

Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes:

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1

 */

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        if (A.empty())return res;
        int N = A.size(), M = A[0].size();
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                res = max(res, compare(A, B, r, c));
                res = max(res, compare(B, A, r, c));
            }
        }
        return res;
    }
private:
    int compare(vector<vector<int>>&a, vector<vector<int>>&b, int r, int c) {
        int N = (int)a.size(), M = (int)a[0].size();
        int counter = 0;
        for (int i = 0; i < N && i + r < N; i++)
            for (int j = 0; j < M && j + c < M; j++)
                if (1 == a[i][j] && 1 == b[i + r][j + c])
                    counter++;
        return counter;
    }
};