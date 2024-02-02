class Trie {

private:

	class Node {

	public:
		string val;
		Node* child['z' - 'a'] = { nullptr, };

	};


public
	:
	Trie() {
		mNode = new Node();
	}

	void insert(string word) {

		if (word.empty())
		{
			return;
		}

		insert(mNode, word, 0);

	}

	bool search(string word) {

		return search(mNode, word, 0);

	}

	bool startsWith(string prefix) {
		
		return startWith(mNode, prefix, 0);

	}

private:

	void insert(Node* node, string& word, int index)
	{
		auto* chNode = node->child[word[index]];

		if (nullptr == chNode)
		{
			chNode = new Node();
		}

		if (word.size() - 1 == index)
		{
			chNode->val = word;
			return;
		}
		else
		{
			insert(chNode, word, index + 1);
		}
		
	}

	bool search(Node* node, string& word, int index)
	{
		auto* chNode = node->child[word[index]];

		if (nullptr == chNode)
		{
			return false;
		}

		if (word.size() - 1 == index)
		{
			return chNode->val == word;
		}

		else
		{
			return search(chNode, word, index + 1);
		}
		
	}

	bool startWith(Node* node, string& prefix, int index)
	{
		auto* c = node->child[prefix[index]];

		if (nullptr == c)
		{
			return false;
		}

		if (prefix.size() - 1 == index)
		{
			return true;
		}
		else
		{
			return startWith(c, prefix, index + 1);
		}
	}


private:
	Node* mNode = nullptr;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */