/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

 */

class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        stringstream ss;
        ss << str;
        string word;
        int i = 0;
        unordered_map<char, string>c2s;
        unordered_map<string, char>s2c;
        while (ss >> word)
        {
            if (c2s.find(pattern[i]) == c2s.end() && s2c.find(word) == s2c.end())
            {
                c2s[pattern[i]] = word;
                s2c[word] = pattern[i];
            }
            else
            {
                if (c2s[pattern[i]] != word || s2c[word] != pattern[i])
                    return false;
            }
            i++;
        }
        return i == pattern.size();
    }
};