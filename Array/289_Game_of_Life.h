class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {

		int maxY = static_cast<int>(board.size());
		int maxX = static_cast<int>(board[0].size());

		vector<vector<int>> ret = board;

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				int lCount = 0;

				if (x + 1 < maxX && board[y][x + 1]) lCount++;

				if (0 <= x - 1 && board[y][x - 1]) lCount++;

				if (y + 1 < maxY && board[y + 1][x]) lCount++;

				if (0 <= y - 1 && board[y - 1][x]) lCount++;

				if (y + 1 < maxY && x + 1 < maxX && board[y + 1][x + 1]) lCount++;

				if (0 <= y - 1 && x + 1 < maxX && board[y - 1][x + 1]) lCount++;

				if (y + 1 < maxY && 0 <= x - 1 && board[y + 1][x - 1]) lCount++;

				if (0 <= y - 1 && 0 <= x - 1 && board[y - 1][x - 1]) lCount++;

				if (lCount < 2 && board[y][x]) ret[y][x] = 0;
				else if (3 < lCount && board[y][x]) ret[y][x] = 0;
				else if (3 == lCount && !board[y][x]) ret[y][x] = 1;
			}
		}

		board = ret;
	}
};