/*

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation

 */

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> startWords, endWords;
        startWords.insert(beginWord);
        if (dict.count(endWord)) endWords.insert(endWord);
        unordered_map<string, vector<string>> children;
        bool flip = false;
        vector<vector<string>> ladders;
        vector<string> ladder;
        ladder.push_back(beginWord);
        if (search(startWords, endWords, dict, children, flip))
            getLadders(beginWord, endWord, children, ladder, ladders);
        return ladders;
    }
private:
    bool search(unordered_set<string>& startWords, unordered_set<string>& endWords,
                unordered_set<string>& dict, unordered_map<string, vector<string>>& children, bool flip)
    {
        if (startWords.empty()) return false;
        if (startWords.size() > endWords.size())
            return search(endWords, startWords, dict, children, !flip);

        for (string e : startWords) dict.erase(e);
        for (string e : endWords) dict.erase(e);
        //BFS startWords
        unordered_set<string> nextlayer;
        bool done = false;
        for (string word : startWords)
        {
            int len = word.length();
            for (int i = 0; i < len; i++)
            {
                string temp(word);
                for (int j = 0; j < 26; j++)
                {
                    temp[i] = j + 'a';
                    if (endWords.count(temp))
                    {
                        done = true;
                        flip ? children[temp].push_back(word) : children[word].push_back(temp);
                    }
                    else if (!done && dict.count(temp))
                    {
                        nextlayer.insert(temp);
                        flip ? children[temp].push_back(word) : children[word].push_back(temp);
                    }
                }
            }
        }
        return done || (search(nextlayer, endWords, dict, children, flip));
    }

    void getLadders(string& start, string& end, unordered_map<string, vector<string> >& children,
                    vector<string>& ladder, vector<vector<string> >& ladders)
    {
        if (start == end)
        {
            ladders.push_back(ladder);
            return;
        }
        for (string child : children[start])
        {
            ladder.push_back(child);
            getLadders(child, end, children, ladder, ladders);
            ladder.pop_back();
        }
    }
};