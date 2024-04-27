class Solution {
public:
	bool isPossible(vector<int>& A) {

		unordered_map<int, int> left, end;

		for (int n : A)
			left[n]++;

		for (int n : A)
		{	
			if (0 == left[n])
				continue;

			left[n]--;

			if (0 < end[n - 1])
			{
				end[n - 1]--;
				end[n]++;
			}
			else if (0 < left[n + 1] && 0 < left[n + 2])
			{
				left[n + 1]--;
				left[n + 2]--;
				end[n + 2]++;
			}
			else
			{
				return false;
			}

		}

		return true;
	}
};

https://leetcode.com/problems/split-array-into-consecutive-subsequences/solutions/106514/c-python-esay-understand-solution/


class Solution {

	vector<vector<int>> ret;

	bool dfs(int index, vector<int>& nums, vector<int> nlist, vector<bool>& visit, int count, int pre)
	{
		if (3 <= nlist.size())
		{
			ret.push_back(nlist);
			return true;
		}

		for (int i = index; i < nums.size(); i++)
		{
			if (visit[i])
			{
				continue;
			}

			if (0 < index && nums[i] != pre + 1)
			{
				continue;
			}

			visit[i] = true;

			nlist.push_back(nums[i]);

			if (dfs(i + 1, nums, nlist, visit, count + 1, nums[i]))
			{
				count = 0;
				nlist.clear();
			}
			else
			{
				nlist.pop_back();
			}

		}

		return false;
	}


public:
	bool isPossible(vector<int>& nums) {

		vector<bool> visit(nums.size(), false);

		vector<int>  nlist;

		dfs(0, nums, nlist, visit, 0, 0);

		int sum = 0;

		for (auto& v : ret)
		{
			sum += v.size();
		}

		return 1 < ret.size() || nums.size() == sum;

	}
};