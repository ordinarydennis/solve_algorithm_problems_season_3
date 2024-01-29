class Solution {

	vector<vector<int>> ret;

	void dfs(int index, int n,  int k, int count, vector<int>& result)
	{
		if (k == count)
		{
			ret.push_back(result);
			return;
		}

		for (int i = index + 1; i <= n; i++)
		{
			result.push_back(i);
			dfs(i, n, k, count + 1, result);
			result.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {

		vector<int> result;

		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			result.push_back(i);
			dfs(i, n, k, count + 1, result);
			result.pop_back();
		}

		return ret;
	}
};

class Solution {
public:
	vector<vector<int>> ans;

	void helper(int idx, int k, vector<int>& current, int n)
	{
		if (current.size() == k)    // base case
		{
			ans.push_back(current);
			return;
		}

		for (int i = idx;i < n + 1;i++)
		{
			current.push_back(i);  //consider the current element i
			helper(i + 1, k, current, n); // generate combinations
			current.pop_back(); //proceed to next element
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int>current;
		helper(1, k, current, n);
		return ans; //return answer
	}
};

//https://leetcode.com/problems/combinations/submissions/1159766124/

//backtracking
//https://youngdroidstudy.tistory.com/entry/%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9-%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9%EC%9D%98-%EC%84%A4%EB%AA%85%EA%B3%BC-%EA%B0%84%EB%8B%A8%ED%95%9C-%EC%98%88%EC%A0%9C%ED%92%80%EC%9D%B4