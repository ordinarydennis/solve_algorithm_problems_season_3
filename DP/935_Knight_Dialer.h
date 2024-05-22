class Solution {
public:
	vector<vector<int>> memo;
	int n;
	int MOD = 1e9 + 7;
	vector<vector<int>> jumps = {
		{4, 6},
		{6, 8},
		{7, 9},
		{4, 8},
		{3, 9, 0},
		{},
		{1, 7, 0},
		{2, 6},
		{1, 3},
		{2, 4}
	};

	int dp(int remain, int square) {
		if (remain == 0) {
			return 1;
		}

		if (memo[remain][square] != 0) {
			return memo[remain][square];
		}

		int ans = 0;
		for (int nextSquare : jumps[square]) {
			ans = (ans + dp(remain - 1, nextSquare)) % MOD;
		}

		memo[remain][square] = ans;
		return ans;
	}

	int knightDialer(int n) {
		this->n = n;
		memo.resize(n + 1, vector(10, 0));
		int ans = 0;
		for (int square = 0; square < 10; square++) {
			ans = (ans + dp(n - 1, square)) % MOD;
		}

		return ans;
	}
};



class Solution {

private:
	vector<vector<int>> PAD = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{-1, 0, -1},
	};

	vector<vector<int>> DIR = {
		{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2},
		{2, 1}, {2, -1}, {1, 2}, {1, -2},
	};

	map<pair<int, int>, int> memo;

	static constexpr int MOD = 1e9 + 7;

private:
	int dfs(int x, int y, int n, int c)
	{
		pair<int, int> k = { PAD[y][x], c };

		if (memo.count(k))
		{
			return memo[k];
		}

		if (c == n)
		{
			return 1;
		}

		int ret = 0;

		for (const auto& d : DIR)
		{
			int cy = y + d[0];
			int cx = x + d[1];

			if (cy < 0 || cx < 0)
				continue;

			if (3 < cy || 2 < cx)
				continue;

			if (-1 == PAD[cy][cx])
				continue;
			
			ret = (ret + dfs(cx, cy, n, c + 1)) % MOD;
		}

		memo[k] = ret;

		return ret;
	}


public:
	int knightDialer(int n) {

		int ret = 0;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (-1 == PAD[y][x])
					continue;

				ret = (ret + dfs(x, y, n, 1)) % MOD;
			}
		}

		return ret;
	}
};

class Solution {

	inline static vector<pair<int, int>> dir = {
		{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2},
		{2, 1}, {2, -1}, {1, 2}, {1, -2},
	};

	map<tuple<int, int, int>, int> memo;

	int MOD = 1e9 + 7;

private:
	int dfs(vector<vector<int>>& pad, int x, int y, int N, int c) {
		
		tuple<int, int, int> t = { x, y, c };

		if (memo.count(t))
			return memo[t];

		if (N == c)
			return 1;

		int ret = 0;

		for (const auto& [yd, xd] : dir) {
			int cy = y + yd;
			int cx = x + xd;

			if (cy < 0 || cx < 0 || cy > 3 || cx > 2)
				continue;
			if (pad[cy][cx] == -1)
				continue;


			ret = (ret + dfs(pad, cx, cy, N, c + 1)) % MOD;

		}

		memo[t] = ret;
		return ret;
	}

public:
	int knightDialer(int n) {
		vector<vector<int>> pad = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{-1, 0, -1}
		};

		int ret = 0;

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 3; x++) {
				if (pad[y][x] != -1) {
					ret = (ret + dfs(pad, x, y, n, 1)) % MOD;
				}
			}
		}

		return ret;
	}
};


/*
`int MOD = 1e9 + 7; ` 이 코드는 C++에서 자주 사용되는 문법으로, 특정 수를 나누기 위한 모듈로(modulo) 상수를 정의하는 데 사용됩니다.여기서 `1e9`는 \(10 ^ 9\) (10의 9제곱)을 의미하며, `1e9 + 7`은 1, 000, 000, 007을 의미합니다.

### 왜 이 숫자를 사용할까요 ?

1, 000, 000, 007은 매우 큰 소수입니다.프로그래밍에서는 특히 수학적 문제나 알고리즘 문제를 해결할 때 다음과 같은 이유로 큰 소수를 모듈로 값으로 사용하는 것이 유리합니다 :

1. * *오버플로 방지 * *: 컴퓨터는 일반적으로 정수형(int) 변수를 사용하여 제한된 범위의 수만을 저장할 수 있습니다.특히 큰 수를 다룰 때, 이 수들을 직접 계산하는 대신에 모듈로 연산을 통해 결과를 작은 범위 내로 유지시킬 수 있습니다.이는 특히 합, 곱셈과 같은 연산에서 오버플로를 방지할 수 있습니다.

2. * *분배 법칙 유지 * *: 모듈로 연산은 분배 법칙, 결합 법칙, 교환 법칙이 성립하기 때문에, 일반적인 수학 연산과 유사한 방식으로 코드를 작성할 수 있습니다.

3. * *알고리즘에서의 사용 * *: 많은 알고리즘, 특히 해시 함수나 동적 프로그래밍, 그래프 이론에서 큰 소수 모듈로는 결과의 무결성을 유지하고 예상치 못한 패턴이나 충돌을 피하는 데 도움이 됩니다.

1, 000, 000, 007과 같은 큰 소수를 사용하는 것은 이러한 이유로 흔히 보는 관행입니다.대체로 이 값은 계산 결과가 안전하게 int 범위 내에 들어가도록 도와주며, 특히 경쟁 프로그래밍이나 알고리즘 문제에서 많이 사용됩니다.

1e9에서의 e는 공학적 표기법(Engineering notation)에서 사용되며, "10의 거듭제곱"을 의미합니다. 따라서 1e9는
1×10^9 을 의미하며, 이는 1,000,000,000 즉 10억을 나타냅니다.

이 표기법은 특히 과학이나 공학 분야에서 매우 크거나 매우 작은 수를 간편하게 표현할 때 자주 사용됩니다. 프로그래밍에서도 이 방식을 사용하여 가독성을 높이고, 코드를 간결하게 만들 수 있습니다.
*/





class Solution {

	inline static vector<pair<int, int>> dir = {
		{-2, 1},
		{-2, -1},
		{-1, 2},
		{-1, -2},
		{2, 1},
		{2, -1},
		{1, 2},
		{1, -2},
	};

	map<tuple<int, int, int>, int> memo;

private:
	int dfs(vector<vector<int>>& pad, int x, int y, vector<bool>& v, int n, int c)
	{
		tuple<int, int, int> t = { x, y, c };
		
		if (memo.count(t))
		{
			return memo[t];
		}

		if (n == c)
		{
			return 1;
		}
		
		int ret = 0;

		for (const auto& [yd, xd] : dir)
		{
			int cy = y + yd;
			int cx = x + xd;

			if (cy < 0 || cx < 0)
			{
				continue;
			}
			if (3 < cy || 2 < cx)
			{
				continue;
			}

			if (-1 == pad[cy][cx])
			{
				continue;
			}

			if (v[pad[cy][cx]])
			{
				continue;
			}
		
			//v[pad[cy][cx]] = true;

			int n = dfs(pad, xd, yd, v, n, c + 1);
			
			tuple<int, int, int> t = { xd, yd, c + 1};

			memo[t] = n;

			ret += n;

			//v[pad[cy][cx]] = false;
		}

		return ret;
	}


public:
	int knightDialer(int n) {

		vector<vector<int>> pad = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{-1, 0, -1}
		};

		vector<bool> v(9);

		int ret = 0;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (-1 == pad[y][x])
				{
					continue;
				}

				ret += dfs(pad, x, y, v, n, 1);
			}
		}

		return ret;
	}
};