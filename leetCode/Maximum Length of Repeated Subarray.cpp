// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

// Example 1:

// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation:
// The repeated subarray with maximum length is [3, 2, 1].


// Note:

// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), ans = 0;
        vector<int> cur(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int pre = cur[0];
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (A[i - 1] == B[j - 1]) {
                    cur[j] = pre + 1;
                    ans = max(ans, cur[j]);
                } else {
                    cur[j] = 0;
                }
                pre = temp;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};