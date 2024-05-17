class Solution {

	int dfs(int index, int n, vector<string>& arr, std::unordered_map<string, int>& m, int size)
	{
		int ret = 0;

		for (int i = index; i < arr.size(); i++)
		{
			int max = size;

			if (0 == (n & m[arr[i]]))
			{
				n = n & m[arr[i]];
				max += arr[i].size();
				max = dfs(i + 1, n, arr, m, max);
			}
			ret = std::max(ret, max);
		}

		return ret;
	}



public:
	int maxLength(vector<string>& arr) {

		std::unordered_map<string, int> m;

		for (const auto& s : arr)
		{
			int n = 0;

			for (char c : s)
			{
				n = n | (1 << (c - 'a'));
			}

			m[s] = n;
		}

		int ret = 0;

		for (int a = 0 ; a < arr.size() - 1; a++)
		{
			int size = dfs(a, 0, arr, m, 0);
			ret = max(ret, size);
		}

		return ret;
	}
};