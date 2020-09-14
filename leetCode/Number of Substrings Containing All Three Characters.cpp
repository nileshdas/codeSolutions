/*

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
Example 3:

Input: s = "abc"
Output: 1


Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {0, 0, 0}, res = 0, i = 0;
        for (int j = 0; j < s.length(); ++j) {
            ++last[s[j] - 'a'];
            while (last[0] > 0 && last[1] > 0 && last[2] > 0) {
                --last[s[i++] - 'a'];
            }
            res += i;
        }
        return res;
    }
};