class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

		int index = 0;

		for (int t = 0; t < static_cast<int>(arr2.size()); t++)
		{
			for (int i = index; i < static_cast<int>(arr1.size()); i++)
			{
				if (arr1[i] == arr2[t])
				{
					std::swap(arr1[i], arr1[index]);
					index++;
				}
			}
		}

		std::sort(arr1.begin() + index, arr1.end());

		return arr1;
	}
};

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

		std::map<int, int> m;

		for (int n : arr1) m[n]++;

		int t = 0;

		for (int n : arr2) while (m[n]--) arr1[t++] = n;

		for (auto& [n, count] : m) while (0 < count && count--) arr1[t++] = n;
		
		return arr1;
	}
};

https://leetcode.com/problems/relative-sort-array/solutions/336504/c-by-author-lucidly-explained-algorithm-and-then-code-with-comments-in-cpp/
