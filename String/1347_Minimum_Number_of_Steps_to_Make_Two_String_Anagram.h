class Solution {
public:
    int minSteps(string s, string t) {

        std::unordered_map<char, int> memo;

        for (char c : s)
        {
            memo[c]++;
        }

        for (char c : t)
        {
            memo[c]--;
        }

        int ret = 0;

        for (const auto& [c, count] : memo)
        {
            ret += std::max(0, count);
        }

        return ret;

    }
};

//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/editorial/