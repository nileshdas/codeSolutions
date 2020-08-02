// Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j = digits.size() - 1;
        cout << digits.size() << endl;
        int carry = 0;
        while (j >= 0) {
            if (digits[j] == 9) {
                digits[j] = 0;
                carry = 1;
            } else {
                digits[j] = digits[j] + 1;
                return digits;
            }
            j--;
        }
        digits.insert(digits.begin(), 1);

        return digits;
    }
};