class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morse = {
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-", 
            "-.--", "--.." 
        };

        set<string> sset;

        for (const auto& str : words)
        {
            string s;

            for (int i = 0; i < str.size(); i++)
            {
                s += morse[str[i] - 'a'];
            }

            sset.insert(s);
        }


        return sset.size();
    }
};