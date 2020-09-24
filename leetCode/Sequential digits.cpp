/*

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.



Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]


Constraints:

10 <= low <= high <= 10^9

 */

class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int>q;
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }
        vector<int>ret;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            if (f <= h && f >= l) {
                ret.push_back(f);
            }
            if (f > h) {
                break;
            }
            int num = f % 10;
            if (num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }
        return ret;
    }
};