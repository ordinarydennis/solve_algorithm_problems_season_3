class Solution {

	int GetmanhattanDistance(const vector<int>& a, const vector<int>& b)
	{
		return abs(b[0] - a[0]) + abs(b[1] - a[1]);
	}

public:
	int minCostConnectPoints(vector<vector<int>>& points) {

		std::unordered_map<int, pair<int, int>> m;

		for (int a = 0; a < points.size() - 1; a++)
		{
			for (int b = a + 1; b < points.size(); b++)
			{
				int d = GetmanhattanDistance(points[a], points[b]);
				
				auto it = m.find(b);

				if (m.end()  == it)
				{
					m.emplace(b, pair<int, int>{ a, d });
				}
				else
				{
					auto be = m.begin();

					if (d < be->second.second)
					{
						it->second.first = a;
						it->second.second = d;
					}
				}
			}
		}

		int ret = 0;

		for (auto [_, p] : m)
		{
			ret += p.second;
		}

		return ret;

	}
};

int manhattan_distance(vector<int>& p1, vector<int>& p2) {
	return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size();
		vector<bool> visited(n, false);
		unordered_map<int, int> heap_dict;
		for (int i = 0; i < n; ++i) {
			heap_dict[i] = INT_MAX; // Initialize all distances to infinity
		}
		heap_dict[0] = 0; // Start node

		auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
		min_heap.push({ 0, 0 });

		int mst_weight = 0;

		while (!min_heap.empty()) {
			auto [w, u] = min_heap.top();
			min_heap.pop();

			if (visited[u] || heap_dict[u] < w) continue;

			visited[u] = true;
			mst_weight += w;

			for (int v = 0; v < n; ++v) {
				if (!visited[v]) {
					int new_distance = manhattan_distance(points[u], points[v]);
					if (new_distance < heap_dict[v]) {
						heap_dict[v] = new_distance;
						min_heap.push({ new_distance, v });
					}
				}
			}
		}

		return mst_weight;
	}
};

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		int n = points.size();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; //creating heap to store minimum weight
		vector<bool> arr(n);
		heap.push({ 0, 0 });
		int mincost = 0;
		int remaning = 0;
		while (remaning < n) {
			pair<int, int> topElement = heap.top();
			heap.pop();

			int weight = topElement.first;
			int currNode = topElement.second;
			if (arr[currNode]) {
				continue;
			}

			arr[currNode] = true;
			mincost += weight;
			remaning++;

			for (int nextNode = 0; nextNode < n; ++nextNode) {
				if (!arr[nextNode]) {
					int nextWeight = abs(points[currNode][0] - points[nextNode][0]) +
						abs(points[currNode][1] - points[nextNode][1]);

					heap.push({ nextWeight, nextNode });
				}
			}
		}

		return mincost;
	}
};

//https://leetcode.com/problems/min-cost-to-connect-all-points/solutions/1982888/prim-s-algorithm-cpp-solution-with-explanation/

//https://kbj96.tistory.com/15

//https://8iggy.tistory.com/159



class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

		int count = 0;

		int size = static_cast<int>(points.size());

		vector<bool> visit(points.size());

		pq.push(pair<int, int> {0, 0});

		int ret = 0;

		int remain = size;

		while (remain)
		{
			count++;

			auto p = pq.top();

			pq.pop();

			int w = p.first;
			int nodeIndex = p.second;

			if (visit[nodeIndex])
				continue;

			ret += w;

			remain--;

			visit[nodeIndex] = true;

			for (int i = 0; i < size; i++)
			{
				if (visit[i])
					continue;

				int d = abs(points[i][0] - points[nodeIndex][0]) +
					abs(points[i][1] - points[nodeIndex][1]);

				pq.push(pair<int, int> {d, i});
			}	
		}

		return ret;
	}
};