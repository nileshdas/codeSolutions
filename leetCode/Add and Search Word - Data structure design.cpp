// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// Example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z.

class TrieNode {
public:
	bool word;
	TrieNode* children[26];
	TrieNode() {
		word = false;
		memset(children, NULL, sizeof(children));
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* node = root;
		for (char c : word) {
			if (!node -> children[c - 'a']) {
				node -> children[c - 'a'] = new TrieNode();
			}
			node = node -> children[c - 'a'];
		}
		node -> word = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word.c_str(), root);
	}
private:
	TrieNode* root = new TrieNode();

	bool search(const char* word, TrieNode* node) {
		for (int i = 0; word[i] && node; i++) {
			if (word[i] != '.') {
				node = node -> children[word[i] - 'a'];
			} else {
				TrieNode* tmp = node;
				for (int j = 0; j < 26; j++) {
					node = tmp -> children[j];
					if (search(word + i + 1, node)) {
						return true;
					}
				}
			}
		}
		return node && node -> word;
	}
};