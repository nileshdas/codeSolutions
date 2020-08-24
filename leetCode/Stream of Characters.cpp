// Implement the StreamChecker class as follows:

// StreamChecker(words): Constructor, init the data structure with the given words.
// query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.


// Example:

// StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
// streamChecker.query('a');          // return false
// streamChecker.query('b');          // return false
// streamChecker.query('c');          // return false
// streamChecker.query('d');          // return true, because 'cd' is in the wordlist
// streamChecker.query('e');          // return false
// streamChecker.query('f');          // return true, because 'f' is in the wordlist
// streamChecker.query('g');          // return false
// streamChecker.query('h');          // return false
// streamChecker.query('i');          // return false
// streamChecker.query('j');          // return false
// streamChecker.query('k');          // return false
// streamChecker.query('l');          // return true, because 'kl' is in the wordlist


// Note:

// 1 <= words.length <= 2000
// 1 <= words[i].length <= 2000
// Words will only consist of lowercase English letters.
// Queries will only consist of lowercase English letters.
// The number of queries is at most 40000.

class Trie {
    unordered_map<char, Trie *> char_map;
    bool word_ends;
public:
    Trie() {
        word_ends = false;
    }

    void insert(string word) {
        if (word.length() == 0)
            return;

        Trie *temp = this;
        for (auto ch : word) {
            if (temp->char_map.find(ch) != temp->char_map.end()) {
                temp = temp->char_map[ch];
            } else {
                temp->char_map[ch] = new Trie();
                temp = temp->char_map[ch];
            }
        }

        temp->word_ends = true;
    }

    bool search(string word) {
        if (word.length() == 0)
            return false;

        Trie *temp = this;
        for (auto ch : word) {
            if (temp->char_map.find(ch) == temp->char_map.end())
                return false;
            temp = temp->char_map[ch];
            if (temp->word_ends)
                return true;
        }
        return temp->word_ends;
    }
};

class StreamChecker {
    Trie my_trie;
    string str = "";
    int w_len = 0;
public:
    StreamChecker(vector<string>& words) {
        for (auto w : words) {
            reverse(w.begin(), w.end());
            w_len = max(w_len, (int)w.length());
            my_trie.insert(w);
        }
    }

    bool query(char letter) {
        str = letter + str;

        if (str.length() > w_len)
            str.pop_back();

        return my_trie.search(str);
    }
};