class MagicDictionary {
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {


        mDictionary = std::move(dictionary);

    }

    bool search(string searchWord) {

        for (const auto& d : mDictionary)
        {
            if (Check(d, searchWord))
                return true;
        }
        
        return false;
    }


private:

    bool Check(string d, string t)
    {
        if (d.size() != t.size())
        {
            return false;
        }

        if (d == t)
        {
            return false;
        }

        std::unordered_map<char, int> memo;

        int max = 0;
        int min = 0;

        for (int i = 0; i < d.size(); i++)
        {
            memo[d[i]]++;
            memo[t[i]]--;
        }

        for (const auto& [c, count] : memo)
        {
            if (1 == count)
            {
                max++;
			}
            
            else if (-1 == count)
            {
                min++;
            }

        }

        return 1 == max && 1 == min;
    }


private:
    vector<string>  mDictionary;

};


/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
