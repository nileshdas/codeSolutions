class Solution {
public:
	int squareSum(int n) {
		int tmp;
		int sum = 0;
		while (n) {
			tmp = n % 10;
			sum += tmp * tmp;
			n /=  10;
		}
		return sum;
	}
	bool isHappy(int n) {
		int slow, fast;
		fast = slow = n;
		do {
			slow = squareSum(slow);
			fast = squareSum(fast);
			fast = squareSum(fast);
			if (fast == 1) {return 1;}
		} while (slow != fast);
		return 0;
	}

};