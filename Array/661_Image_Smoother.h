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

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
		int rows = img.size();
		int cols = img[0].size();

		// Apply the average function to each pixel in the image matrix
		vector<vector<int>> result(rows, vector<int>(cols, 0));
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				result[r][c] = calculateAverage(img, r, c, rows, cols);
			}
		}

		return result;
	}

private:
	int calculateAverage(const vector<vector<int>>& img, int r, int c, int rows, int cols) {
		int total = 0;
		int count = 0;

		// Define the boundaries for the neighboring pixels
		int top = max(0, r - 1);
		int bottom = min(rows, r + 2);
		int left = max(0, c - 1);
		int right = min(cols, c + 2);

		// Iterate over the neighboring pixels and calculate the sum and count
		for (int row = top; row < bottom; row++) {
			for (int col = left; col < right; col++) {
				total += img[row][col];
				count += 1;
			}
		}

		// Calculate and return the average value for the pixel
		return total / count;
	}
};
//https://leetcode.com/problems/image-smoother/solutions/4423391/video-give-me-10-minutes-how-we-think-about-a-solution/


class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

		vector<vector<int>> ret(img.size(), vector<int>(img[0].size()));

		int maxX = img[0].size() - 1;
		int maxY = img.size() - 1;

		for (int y = 0; y <= maxY; y++)
		{
			for (int x = 0; x <= maxX; x++)
			{
				int beginX = std::max(x - 1,  0);
				int endX = std::min(x + 1,  maxX);

				int beginY = std::max(y - 1,  0);
				int endY = std::min(y + 1,  maxY);

				int sum = 0;
				int count = 0;

				for(int iy = beginY; iy <= endY; iy++)
				{
					for(int ix = beginX; ix <= endX; ix++)
					{
						sum += img[iy][ix];
						count++;
					}
				}

				ret[y][x] = sum / count;

			}
		}

		return ret;
	}
};