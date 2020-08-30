// Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

// A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

// Return the maximum length of a subarray with positive product.



// Example 1:

// Input: nums = [1,-2,-3,4]
// Output: 4
// Explanation: The array nums already has a positive product of 24.
// Example 2:

// Input: nums = [0,1,-2,-3,-4]
// Output: 3
// Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
// Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
// Example 3:

// Input: nums = [-1,-2,-3,0,1]
// Output: 2
// Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
// Example 4:

// Input: nums = [-1,2]
// Output: 1
// Example 5:

// Input: nums = [1,2,3,5,-6,4,0,10]
// Output: 4


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int start = -1, neg = 0, res = 0, firstneg = -2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                start = i;
                neg = 0;
                firstneg = -2;
            } else {
                if (nums[i] < 0)neg++;
                if (neg == 1 && firstneg == -2) {firstneg = i;}
                if (neg % 2 == 0 ) res = max(res, i - start);
                else if (firstneg > -2)res =  max(res, i - firstneg);
            }
        }
        return res;
    }
};