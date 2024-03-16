class Solution {
public:
    bool divisorGame(int n) {

        return (n % 2) == 0;

    }
};


class Solution {

    bool dfs(int n, bool aTurn)
    {
        if (n == 0)
            return aTurn;

        return dfs(n - 1, !aTurn);
    }

public:
    bool divisorGame(int n) {

        return dfs(n, true);

    }
};