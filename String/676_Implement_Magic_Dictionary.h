class MagicDictionary {
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {

        mDictionary = std::move(dictionary);

    }

    bool search(string searchWord) {

        for (const auto& d : mDictionary)
            if (Check(d, searchWord))
                return true;
        
        return false;
    }


private:

    bool Check(string d, string t)
    {
        if (d.size() != t.size())
            return false;

        if (d == t)
            return false;

        int count = 0;

        for (int i = 0; i < d.size(); i++)
            if(d[i] != t[i])
                count++;

        return 1 == count;
    }


private:
    vector<string>  mDictionary;

};


class MagicDictionary {
public:

	unordered_set<string> set;

	MagicDictionary() {
	}

	void buildDict(vector<string> dictionary) {
		for (string str : dictionary)
			set.insert(str);
	}

	bool search(string searchWord) {
		for (string s : set) {
			if (s.size() == searchWord.size()) {
				int cnt = 0;
				for (int i = 0;i < s.size();i++) {
					if (s[i] != searchWord[i]) cnt++;
				}
				if (cnt == 1) return true;
			}
		}
		return false;
	}

};

//https://leetcode.com/problems/implement-magic-dictionary/solutions/956713/easy-understanding-c/

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */