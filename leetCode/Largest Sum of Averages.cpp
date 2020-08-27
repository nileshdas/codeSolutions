// We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

// Note that our partition must use every number in A, and that scores are not necessarily integers.

// Example:
// Input:
// A = [9,1,2,3,9]
// K = 3
// Output: 20
// Explanation:
// The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
// We could have also partitioned A into [9, 1], [2], [3, 9], for example.
// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.


// Note:

// 1 <= A.length <= 100.
// 1 <= A[i] <= 10000.
// 1 <= K <= A.length.
// Answers within 10^-6 of the correct answer will be accepted as correct.

class Solution {
public:
    double m[101][101] = {};
    double largestSumOfAverages(vector<int>& A, int K, int p = 0) {
        if (p >= A.size() || m[K][p] > 0) return m[K][p];
        for (double i = p, sum = 0; i <= A.size() - K; ++i) {
            sum += A[i];
            if (K == 1 && i < A.size() - 1) continue;
            m[K][p] = max(m[K][p], sum / (i - p + 1) + largestSumOfAverages(A, K - 1, i + 1));
        }
        return m[K][p];
    }
};