//use recursion
class Trie {

private:

	class Node {

	public:
		bool mIsWord = false;
		Node* mChild['z' - 'a' + 1] = { nullptr, };

	};


public:

	void insert(string word)
	{
		insert(&mNode, word, 0);
	}
	
	void insert(Node* node, string& word, int index)
	{
		if(word.size() == index)
		{
			node->mIsWord = true;
			return;	
		}

		auto* chNode = node->mChild[word[index] - 'a'];

		if (nullptr == chNode)
		{
			chNode = new Node();
			node->mChild[word[index] - 'a'] = chNode;
		}

		insert(chNode, word, index + 1);
	}

	bool search(string word) {

		return search(&mNode, word, 0);

	}

	bool search(Node* node, string& word, int index)
	{
		if(word.size() == index)
			return node->mIsWord;

		auto* chNode = node->mChild[word[index] - 'a'];

		if (nullptr == chNode)
			return false;

		return search(chNode, word, index + 1);
	}


	bool startsWith(string prefix) {
		
		return startWith(&mNode, prefix, 0);

	}

	bool startWith(Node* node, string& prefix, int index)
	{
		if(prefix.size() == index)
			return true;

		auto* cNode = node->mChild[prefix[index] - 'a'];

		if (nullptr == cNode)
			return false;
	
		return startWith(cNode, prefix, index + 1);
	}


private:
	Node mNode;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


//use loop
class Trie {

private:

	class Node {

	public:
		bool mIsWord = false;
		Node* mChild['z' - 'a' + 1] = { nullptr, };

	};


public:

	void insert(string word) {

		Node* node = &mNode;

		for(auto c : word)
		{
			if (nullptr ==  node->mChild[c - 'a'])
				node->mChild[c - 'a'] = new Node();

			 node =  node->mChild[c - 'a'];
		}

		node->mIsWord = true;

	}

	bool search(string word, bool isPrefix = false) {

		Node* node = &mNode;

		for(auto c : word)
		{
			if (nullptr == node->mChild[c - 'a'])
			{
				return false;
			}

			node = node->mChild[c - 'a'];
		}

		return (isPrefix) ? true :  node->mIsWord;
	}

	bool startsWith(string prefix) {
		
		return search(prefix, true);
	}


private:
	Node mNode;

};

//https://leetcode.com/problems/implement-trie-prefix-tree/solutions/3180933/solution/