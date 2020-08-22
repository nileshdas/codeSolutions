// Given two sorted arrays nums1 and nums2 of size m and n respectively.

// Return the median of the two sorted arrays.

// Follow up: The overall run time complexity should be O(log (m+n)).



// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// Example 3:

// Input: nums1 = [0,0], nums2 = [0,0]
// Output: 0.00000
// Example 4:

// Input: nums1 = [], nums2 = [1]
// Output: 1.00000
// Example 5:

// Input: nums1 = [2], nums2 = []
// Output: 2.00000


// Constraints:

// nums1,length == m
// nums2,length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = (m + n) / 2;
        int num1 = findKth(nums1, 0, m, nums2, 0, n, k + 1);
        if ((n + m) % 2 == 0)
        {
            int num2 = findKth(nums1, 0, m, nums2, 0, n, k);
            return (num1 + num2) / 2.0;
        }
        else return num1;
    }
    int findKth(vector<int> & nums1, int nums1_left, int nums1_right, vector<int> & nums2, int nums2_left, int nums2_right, int k)
    {
        int m = nums1_right - nums1_left;
        int n = nums2_right - nums2_left;
        if (m > n) return findKth(nums2, nums2_left, nums2_right, nums1, nums1_left, nums1_right, k);
        else if (m == 0)
            return nums2[nums2_left + k - 1];
        else if (k == 1)
            return min(nums1[nums1_left], nums2[nums2_left]);
        else {
            int s1LeftCount = min (k / 2, m);
            int s2LeftCount = k - s1LeftCount;
            if (nums1[nums1_left + s1LeftCount - 1] == nums2[nums2_left + s2LeftCount - 1])
                return nums1[nums1_left + s1LeftCount - 1];
            else if (nums1[nums1_left + s1LeftCount - 1] < nums2[nums2_left + s2LeftCount - 1])
                return findKth(nums1, nums1_left + s1LeftCount, nums1_right, nums2, nums2_left, nums2_right, k - s1LeftCount);
            else
                return findKth(nums1, nums1_left, nums1_right, nums2, nums2_left + s2LeftCount, nums2_right, k - s2LeftCount);
        }
    }
};