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


//Method 3: Using Dynamic Programming with 1D Array
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		vector<int> prevRow;

		for (int i = 0; i < numRows; i++) {
			vector<int> currentRow(i + 1, 1);

			for (int j = 1; j < i; j++) {
				currentRow[j] = prevRow[j - 1] + prevRow[j];
			}

			result.push_back(currentRow);
			prevRow = currentRow;
		}

		return result;
	}
};

//is it better than mine?
