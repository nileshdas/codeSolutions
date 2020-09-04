/*

Given s1, s2, and s3, find whether s3 is formed by the interleaving of s1 and s2.



Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lower-case English letters.

 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        bool t[s1.length() + 1][s2.length() + 1];

        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    t[i][j] = true;
                }
                else if (i == 0) {
                    t[i][j] =  t[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    t[i][j] = t[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    t[i][j] = (t[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (t[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return t[s1.length()][s2.length()] ;
    }
};