class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

		std::unordered_map<int, int> m;

		for (int n : arr)
		{
			m[n]++;
		}

		auto l = [](vector<int>& a, vector<int>& b) {
			return (a[0] > b[0]) || (a[0] == b[0] && a[1] > b[1]);
		};

		std::priority_queue <vector<int>, vector<vector<int>>, decltype(l)> q;

		for (const auto& [n, count] : m)
		{
			q.push(vector<int> {count, n});
		}
		
		for (int i = 0; i < k; i++)
		{
			auto v = q.top();

			q.pop();

			if (--v[0])
			{
				q.push(v);
			}
		}

		return q.size();
	}
};