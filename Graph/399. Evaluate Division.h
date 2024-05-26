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
