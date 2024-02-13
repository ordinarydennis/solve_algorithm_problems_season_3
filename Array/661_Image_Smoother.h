class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

		vector<vector<int>> ret(img.size(), vector<int>(img[0].size()));

		for (int y = 0; y < img.size(); y++)
		{
			int sum = 0;

			for (int x = 0; x < img[0].size(); x++)
			{
				sum = img[y][x];

				int count = 1;

				if (y + 1 < img.size())
				{
					sum += img[y + 1][x];
					count++;
				}

				if (0 <= y - 1)
				{
					sum += img[y - 1][x];
					count++;
				}

				if (x + 1 < img[0].size())
				{
					sum += img[y][x + 1];
					count++;
				}

				if (0 <= x - 1)
				{
					sum += img[y][x - 1];
					count++;
				}

				if (y + 1 < img.size() && x + 1 < img[0].size())
				{
					sum += img[y + 1][x + 1];
					count++;
				}

				if (0 <= y - 1 && 0 <= x - 1)
				{
					sum += img[y - 1][x - 1];
					count++;
				}

				if (0 <= y - 1 && x + 1 < img[0].size())
				{
					sum += img[y - 1][x + 1];
					count++;
				}

				if (y + 1 < img.size() && 0 <= x - 1)
				{
					sum += img[y + 1][x - 1];
					count++;
				}

				ret[y][x] = sum / count;

			}
		}



		return ret;
	}
};