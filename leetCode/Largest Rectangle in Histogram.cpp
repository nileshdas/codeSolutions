// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int>s;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int length = s.empty() ? i : i - s.top() - 1;
                if (h * length > maxArea) maxArea = h * length;

            }
            s.push(i);
        }
        return maxArea;
    }
};