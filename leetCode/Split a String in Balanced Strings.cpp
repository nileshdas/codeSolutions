// Balanced strings are those who have equal quantity of 'L' and 'R' characters.

// Given a balanced string s split it in the maximum amount of balanced strings.

// Return the maximum amount of splitted balanced strings.



// Example 1:

// Input: s = "RLRRLLRLRL"
// Output: 4
// Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
// Example 2:

// Input: s = "RLLLLRRRLR"
// Output: 3
// Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
// Example 3:

// Input: s = "LLLLRRRR"
// Output: 1
// Explanation: s can be split into "LLLLRRRR".
// Example 4:

// Input: s = "RLRRRLLRLL"
// Output: 2
// Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'


// Constraints:

// 1 <= s.length <= 1000
// s[i] = 'L' or 'R'

class Solution {
public:
    int balancedStringSplit(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                left++;
            } else if (s[i] == 'R') {
                right++;
            }
            if (left == right) {
                res++;
                left = 0;
                right = 0;
            }
        }
        return res;
    }
};