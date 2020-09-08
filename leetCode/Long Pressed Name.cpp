/*

Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.


Constraints:

1 <= name.length <= 1000
1 <= typed.length <= 1000
The characters of name and typed are lowercase letters.


 */

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = typed.size();
        int j = 0;
        int i;
        int p = name.size();
        for (i = 0; i < n; i++) {
            if (typed[i] == name[j] && j < p) {
                j++;
            }
            else if (!i ||  typed[i] != typed[i - 1]) {
                return false;
            }
        }


        return j == p;

    }
};