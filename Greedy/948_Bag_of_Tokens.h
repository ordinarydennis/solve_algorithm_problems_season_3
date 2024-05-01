class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int power) {

		sort(tokens.begin(), tokens.end());

		int s = 0;
		int e = tokens.size() - 1;

		int score = 0;

		while(s <= e)
		{
			if (tokens[s] <= power)
			{
				power -= tokens[s];
				score++;
				s++;
			}
			else
			{
				if (score && s < e)
				{
					score--;
					power += tokens[e];
					e--;
				}
				else
				{
					break;
				}
			}
		}

		return score;
	}
};

class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int power) {

		sort(tokens.begin(), tokens.end());

		int s = 0;
		int e = tokens.size() - 1;

		int score = 0;

		while (s <= e)
		{
			if (tokens[s] <= power)
			{
				score++;
				power -= tokens[s];
				s++;
			}
			else
			{
				if (0 < score && 0 < e - s)
				{
					power += tokens[e];
					e--;
					score--;
				}
				else
				{
					s++;
				}
			}
		}

		return score;
	}
};
