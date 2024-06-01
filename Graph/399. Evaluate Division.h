class Solution {

	double dfs(const string& curStr, const string& target, double accu, unordered_map<string, unordered_map<string, double>>& graph,
		unordered_set<string>& visit)
	{
		visit.insert(curStr);

		auto& neigbors = graph[curStr];

		double ret = -1.0;

		auto it = neigbors.find(target);

		if (neigbors.end() != it)
		{
			ret = accu * it->second;
		}
		else
		{
			for (auto& [devisor, val] : neigbors)
			{
				if (visit.count(devisor))
					continue;

				ret = dfs(devisor, target, accu * val, graph, visit);

				if (-1.0 != ret)
				{
					break;
				}
			}
		}
		
		visit.erase(curStr);
		
		return ret;
	}


public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		unordered_map<string, unordered_map<string, double>> graph;

		for (int i = 0; i < equations.size(); i++)
		{
			string dividend = equations[i][0];
			string devisor = equations[i][1];

			graph[dividend][devisor] = values[i];
			graph[devisor][dividend] = 1.0 / values[i];
		}

		vector<double> ret;

		unordered_set<string> visit;

		for (int i = 0; i < queries.size(); i++)
		{
			string cur = queries[i][0];
			string target = queries[i][1];

			if (0 == graph.count(cur) || 0 == graph.count(target))
			{
				ret.push_back(-1.0);
				continue;
			}

			auto neighborsIt = graph.find(cur);

			if (neighborsIt->second.count(target))
			{
				ret.push_back(graph[cur][target]);
				continue;
			}

			ret.push_back(dfs(cur, target, 1.0, graph, visit));
		}

		return ret;
	}
};



class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		unordered_map<string, unordered_map<string, double>> graph;

		// Step 1). Build the graph from the equations
		for (int i = 0; i < equations.size(); i++) {
			string dividend = equations[i][0], divisor = equations[i][1];
			double quotient = values[i];

			graph[dividend].insert({ divisor, quotient });
			graph[divisor].insert({ dividend, 1.0 / quotient });
		}

		// Step 2). Evaluate each query via backtracking (DFS)
		vector<double> results(queries.size());
		for (int i = 0; i < queries.size(); i++) {
			string dividend = queries[i][0], divisor = queries[i][1];

			if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
				results[i] = -1.0;
			else if (dividend == divisor)
				results[i] = 1.0;
			else {
				set<string> visited;
				results[i] = backtrackEvaluate(graph, dividend, divisor, 1, visited);
			}
		}

		return results;
	}

private:
	double backtrackEvaluate(unordered_map<string, unordered_map<string, double>>& graph, string currNode, string targetNode, double accProduct, set<string>& visited) {
		// Mark the visit
		visited.insert(currNode);
		double ret = -1.0;

		unordered_map<string, double>& neighbors = graph[currNode];
		if (neighbors.find(targetNode) != neighbors.end())
			ret = accProduct * neighbors[targetNode];
		else {
			for (auto& pair : neighbors) {
				string nextNode = pair.first;
				if (visited.find(nextNode) != visited.end())
					continue;
				ret = backtrackEvaluate(graph, nextNode, targetNode, accProduct * pair.second, visited);
				if (ret != -1.0)
					break;
			}
		}

		// Unmark the visit, for the next backtracking
		visited.erase(currNode);
		return ret;
	}
};
