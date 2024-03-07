class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector<vector<int>> ret(numRows);

		int position = 0;

		ret[position].push_back(1);

		position++;

		while (position < numRows)
		{
			auto& pre = ret[position - 1];

			int preSize = static_cast<int>(pre.size());

			for (int i = 0; i <= preSize; i++)
			{
				if (i == 0 || i == preSize)
					ret[position].push_back(1);
				else
					ret[position].push_back(pre[i - 1] + pre[i]);
			}

			position++;
		}

		return ret;

	}
};