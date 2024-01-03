class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {

		std::unordered_map<char, string> m;

		for (const auto& str : dictionary)
		{
			auto it = m.find(str[0]);
			if (m.end() == it)
			{
				m.emplace(str[0], str);
			}
			else if(str.size() < it->second.size())
			{
				it->second = str;
			}
		}

		string str;

		string ret;

		for (int i = 0; i <= sentence.size(); i++)
		{
			if (i == sentence.size() || ' ' == sentence[i])
			{
				auto it = m.find(str[0]);

				if (m.end() == it)
				{
					ret += str;
				}
				else
				{
					auto sub = str.substr(0, it->second.size());
					if (sub == it->second)
					{
						ret += it->second;
					}
					else
					{
						ret += str;
					}
				}

				if (i < sentence.size())
				{
					ret += sentence[i];

				}

				str.clear();
			}
			else
			{
				str += sentence[i];
			}

		}

		return ret;
	}
};

https://leetcode.com/problems/replace-words/solutions/1704741/c-simplest-intuitive-solution-trie/

class TrieNode {
public:
	TrieNode* child[26];
	bool isEnd;

	TrieNode() {
		this->isEnd = false;
		for (int i = 0; i < 26; i++) this->child[i] = NULL;
	}
};

class Solution {
	TrieNode* newNode;
public:
	string check(string word) {
		TrieNode* t = newNode;
		string s = "";

		for (auto i : word) {
			if (!t->child[i - 'a']) break;
			s += i;
			t = t->child[i - 'a'];
			if (t->isEnd) return s;
		}
		return word;
	}

	void insert(string word) {
		TrieNode* temp = newNode;

		for (auto l : word) {
			if (!temp->child[l - 'a']) temp->child[l - 'a'] = new TrieNode();
			temp = temp->child[l - 'a'];
		}

		temp->isEnd = true;
	}

	string replaceWords(vector<string>& dict, string sentence) {
		newNode = new TrieNode();
		for (auto s : dict) insert(s);
		istringstream ss(sentence);
		string word = "", ans = "";

		for (; ss >> word; ) {
			ans += check(word);
			ans += ' ';
		}
		ans.pop_back();

		return ans;
	}
};