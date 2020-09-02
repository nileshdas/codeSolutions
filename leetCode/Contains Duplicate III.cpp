/*

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, long t) {
        int n = nums.size();
        vector<pair<int, int>> numP(n);
        for (int i = 0; i < n; i++)
            numP[i] = {nums[i], i};
        sort(numP.begin(), numP.end(), [](auto i, auto j) {return i.first < j.first;});
        int low = 0, high = 1;
        while (high < n) {
            high = low + 1;
            while (high < n && numP[low].first + t >= numP[high].first) {
                if (abs(numP[low].second - numP[high].second) <= k) return true;
                high++;
            }
            low++;
        }
        return false;
    }
};