// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true

class Solution {
public:
	char asciitolower(char in) {
		if (in <= 'Z' && in >= 'A')
			return in - ('Z' - 'z');
		return in;
	}
	bool isPalindrome(string s) {
		int l = 0;
		int r = s.size() - 1;
		while (l < r) {
			while (!isalnum(s[l]) && l < r) {
				l++;
			}
			while (!isalnum(s[r]) && l < r) {
				r--;
			}
			if ( toupper(s[l]) != toupper(s[r])) {
				return false;
			}
			l++;
			r--;
		}
		return true;
	}
};