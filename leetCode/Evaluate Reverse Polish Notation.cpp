// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Note:

// Division between two integers should truncate toward zero.
// The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
// Example 1:

// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

class Solution {
public:
	int evalRPN(vector<string>& A) {
		stack<int>s;
		int a, b;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] != "+" && A[i] != "-" && A[i] != "*" && A[i] != "/") {
				s.push(stoi(A[i]));

			} else {
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
				if (A[i] == "+")
					s.push(a + b);
				else if (A[i] == "-")
					s.push(a - b);
				else if (A[i] == "*")
					s.push(b * a);
				else
					s.push(a / b);
			}
		}
		int ans = s.top();
		return ans;
	}
};