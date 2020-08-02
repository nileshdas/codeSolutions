// Given an array of integers nums, sort the array in ascending order.



// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]

class Solution {
public:
	void merge(vector<int>&nums, int l, int m, int r)
	{
		int n1 = m - l + 1;
		int n2 = r - m;
		int l1[n1];
		int l2[n2];

		for (int i = 0; i < n1; i++)
			l1[i] = nums[i + l];

		for (int i = 0; i < n2; i++)
			l2[i] = nums[i + 1 + m];

		int i = 0, j = 0, k = l;
		while (i < n1 and j < n2)
		{
			if (l1[i] <= l2[j])
				nums[k++] = l1[i++];
			else
				nums[k++] = l2[j++];
		}


		while (i < n1)
			nums[k++] = l1[i++];
		while (j < n2)
			nums[k++] = l2[j++];
	}
	void mergesort(vector<int>&nums, int l , int r)
	{
		if (l < r)
		{
			int mid = (l + r) / 2;
			mergesort(nums, l, mid);
			mergesort(nums, mid + 1, r);
			merge(nums, l, mid, r);
		}
	}


	vector<int> sortArray(vector<int>& nums) {
		//merge sort
		mergesort(nums, 0 , nums.size() - 1);
		return nums;
	}
};