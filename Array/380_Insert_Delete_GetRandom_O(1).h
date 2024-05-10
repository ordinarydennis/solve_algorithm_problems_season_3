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