// Given an integer array A containing N distinct integers, you have to find all the leaders in the array A.

// An element is leader if it is strictly greater than all the elements to its right side.

// NOTE:The rightmost element is always a leader.



// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 108



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return an integer array denoting all the leader elements of the array.

// NOTE: Ordering in the output doesn't matter.

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size() - 1;
    int maxt = INT_MIN;
    vector<int>res;
    while (n >= 0) {

        if (A[n] > maxt) {
            res.push_back(A[n]);
        }
        maxt = max(A[n], maxt);
        n--;
    }
    return res;
}
