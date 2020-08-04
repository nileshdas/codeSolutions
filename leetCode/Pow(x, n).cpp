// Implement pow(x, n), which calculates x raised to the power n (xn).

// Example 1:

// Input: 2.00000, 10
// Output: 1024.00000

class Solution {
public:
	double myPow(double x, int n) {
		if (n == std::numeric_limits<int>::lowest()) {
			return myPow(1 / x, -(n + 1)) / x;
		}
		if (n < 0) {
			return myPow(1 / x, -n);
		}
		double ans = 1;
		while (n) {
			if (n & 1 == 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return ans;
	}
};