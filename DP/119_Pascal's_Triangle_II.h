class Solution {
public:
	vector<int> getRow(int rowIndex) {

		vector<vector<int>> memo(rowIndex + 1);

		memo[0].push_back(1);

		int curIndex = 1;

		while (curIndex <= rowIndex)
		{
			auto& preRow = memo[curIndex - 1];

			for (int i = 0; i <= preRow.size(); i++)
			{
				if (0 == i || i == preRow.size())
					memo[curIndex].push_back(1);
				else
					memo[curIndex].push_back(preRow[i - 1] + preRow[i]);
			}
			curIndex++;
		}

		return memo[rowIndex];
	}
};