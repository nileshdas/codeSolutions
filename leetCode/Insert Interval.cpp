/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int n = intervals.size();

        if (n == 0) {
            return {newInterval};
        }

        if (intervals[n - 1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
                continue;
            }
            while (i < n && intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                i++;
            }
            ans.push_back(newInterval);
            while (i < n) {
                ans.push_back(intervals[i]);
                i++;
            }
        }


        return ans;
    }
};