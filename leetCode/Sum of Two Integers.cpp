// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = -2, b = 3
// Output: 1

class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int shiftAmount = 1;
        int i = 0;
        int digit = 0;
        bool carryOver = false;

        while (i < 31)
        {
            int bitA = a & 1;
            int bitB = b & 1;
            if (!bitA and !bitB) {
                if (carryOver) {
                    digit = 1;
                    carryOver = false;
                }
                else {
                    digit = 0;
                }
            }
            else if ((!bitA and bitB) or (!bitB and bitA)) {
                if (carryOver) {
                    digit = 0;
                }
                else {
                    digit = 1;
                }
            }
            else if (bitA and bitB) {
                if (carryOver) {
                    digit = 1;
                }
                else {
                    digit = 0;
                    carryOver = true;
                }
            }
            digit = digit << shiftAmount;
            ans = ans | digit;
            a = a >> 1;
            b = b >> 1;
            i++;
            digit = 0;
            shiftAmount++;
        }
        return ans >> 1;
    }
};