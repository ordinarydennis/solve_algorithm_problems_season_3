class RandomizedSet {
public:
	RandomizedSet() {

	}

	bool insert(int val) {

		auto it = m.find(val);

		if (m.end() != it)
		{
			return false;
		}

		list.push_back(val);

		return m.emplace(val, list.size() - 1).second;

	}

	bool remove(int val) {

		auto it = m.find(val);

		if (m.end() == it)
		{
			return false;
		}

		list[it->second] = list[list.size() - 1];

		m[list[list.size() - 1]] = it->second;

		list.pop_back();

		return 0 < m.erase(val);
	}

	int getRandom() {

		return list[rand() % list.size()];

	}


private:
	std::vector<int> list;
	std::unordered_map<int, int> m;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {

        return s.emplace(val).second;

    }

    bool remove(int val) {

        return 0 < s.erase(val);

    }

    int getRandom() {

        auto it = s.begin();

        std::advance(it, rand() % s.size());

        return *(it);
    }


private:
    std::unordered_set<int> s;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */