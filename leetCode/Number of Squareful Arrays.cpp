// Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

// Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].



// Example 1:

// Input: [1,17,8]
// Output: 2
// Explanation:
// [1,8,17] and [17,8,1] are the valid permutations.
// Example 2:

// Input: [2,2,2]
// Output: 1


// Note:

// 1 <= A.length <= 12
// 0 <= A[i] <= 1e9

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        return numSquarefulPerm(A, -1, 0);
    }
    int numSquarefulPerm(vector<int> A, int p = -1, int res = 0) {
        if (p == A.size() - 1) return 1;
        unordered_set<int> s;
        for (auto i = p + 1; i < A.size(); ++i) {
            if (s.insert(A[i]).second && (p == -1 || pow((int)sqrt(A[i] + A[p]), 2) == A[i] + A[p])) {
                swap(A[i], A[p + 1]);
                res += numSquarefulPerm(A, p + 1);
            }
        }
        return res;
    }
};