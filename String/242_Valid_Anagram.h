class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        std::unordered_map<char, int> ana;

        for (char c : s)
            ana[c]++;

        for (char c : t)
            if (--ana[c] < 0)
                return false;

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {

        std::unordered_map<char, int> chk1;
        std::unordered_map<char, int> chk2;

        for (char c : s) chk1[c]++;

        for (char c : t) chk2[c]++;

        //comparison operation is inefficient
        return chk1 == chk2;

    }
};