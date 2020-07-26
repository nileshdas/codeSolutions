// Problem Description

// Given a sorted array A containing N integers both positive and negative.

// You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

// Try to this in O(N) time.


// Problem Constraints
// 1 <= N <= 105.

// -103 <= A[i] <= 103



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return a integer array as described in the problem above.


vector<int> Solution::solve(vector<int> &arr) {

    int mid = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
        {
            mid = i;
            break;
        }
    }
    int i = mid - 1, j = mid;
    vector<int>res(arr.size());
    int k = 0;
    while (i >= 0 && j < arr.size())
    {
        if ((arr[i]*arr[i]) < (arr[j]*arr[j]))
        {
            res[k++] = arr[i] * arr[i];
            i--;
        }
        else
        {
            res[k++] = arr[j] * arr[j];
            j++;
        }
    }
    while (i >= 0)
    {
        res[k++] = arr[i] * arr[i];
        i--;
    }
    while (j < arr.size())
    {
        res[k++] = arr[j] * arr[j];
        j++;
    }

    return res;
}