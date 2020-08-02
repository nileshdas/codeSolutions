// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& arr) {


		vector<vector<int>>ans;

		if (arr.size() == 0)
			return ans;

		sort(arr.begin() , arr.end());


		stack<pair<int, int>>st;

		st.push(make_pair(arr[0][0] , arr[0][1]));   //push the first row

		int n = arr.size();

		for (int i = 1; i < n; i++)
		{
			pair<int, int> temp = st.top();
			//check if temp.second of stack < arr[i][0] intervals are not overlapping
			if (temp.second < arr[i][0])
				st.push(make_pair(arr[i][0], arr[i][1]));

			//check if the tem.second is also less than equal to arr[i][1] which means overlapping is there , so we merge them
			else if (temp.second <= arr[i][1])
			{
				temp.second = arr[i][1];

				st.pop();
				st.push(temp);
			}
		}



		vector<int>row;

		while (!st.empty())
		{
			pair<int, int> temp = st.top();

			st.pop();

			row.push_back(temp.first);
			row.push_back(temp.second);

			ans.push_back(row);

			row.resize(0);
		}

		return ans;
	}
};