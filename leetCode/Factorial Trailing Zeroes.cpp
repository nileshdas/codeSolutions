// Given an integer n, return the number of trailing zeroes in n!.

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int res = 0;
        while (n / 5) {
            int tmp = n / 5;
            res += tmp;
            n = tmp;
        }
        return res;
    }
};