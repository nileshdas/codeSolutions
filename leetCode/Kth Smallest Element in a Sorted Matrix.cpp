// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + r >> 1;
            int cnt = 0;
            int j = n - 1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                cnt += j + 1;
            }
            if (cnt < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};