/*

Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.



Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0


Constraints:

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4

 */

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& a, int k) {
        int a_sum = 0, m_sum = 0, sz = a.size();
        for (auto i = 0, sum = 0; i < min(2, k)* sz; ++i) {
            sum  = max(sum + a[i % sz], a[i % sz]);
            m_sum = max(m_sum, sum);
            if (i < sz) a_sum += a[i];
        }
        while (a_sum > 0 && --k >= 2) {
            m_sum = (m_sum + a_sum) % 1000000007;

        }
        return m_sum;
    }
};