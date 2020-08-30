// Given a non-empty array of unique positive integers A, consider the following graph:

// There are A.length nodes, labelled A[0] to A[A.length - 1];
// There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.



// Example 1:

// Input: [4,6,15,35]
// Output: 4

// Example 2:

// Input: [20,50,9,63]
// Output: 2

// Example 3:

// Input: [2,3,6,7,4,12,21,39]
// Output: 8

// Note:

// 1 <= A.length <= 20000
// 1 <= A[i] <= 100000


class Solution {
public:
    int parent[100001];
    int find (int x)
    {
        if (parent[x] == -1)
            return x;
        else return parent[x] = find(parent[x]);
    }
    bool uni(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        if (xp != yp)
            parent[yp] = xp;
        else return false;
        return true;
    }
    int largestComponentSize(vector<int>& arr)
    {
        unordered_map<int, int> memo;
        memset(parent, -1, sizeof(parent));
        int ret = 0;
        for (int x : arr)
        {
            int flag = 0;
            for (int i = 2; i * i <= x; ++i)
                if (x % i == 0)
                {
                    uni(i, x);
                    uni(x, x / i);
                    flag = 1;
                }
        }
        for (int x : arr)
            ret = max(ret, ++memo[find(x)]);
        return ret;
    }
};