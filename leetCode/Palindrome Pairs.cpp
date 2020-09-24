/*

Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.



Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]


Constraints:

1 <= words.length <= 5000
0 <= words[i] <= 300
words[i] consists of lower-case English letters.

 */

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        if (dict.find("") != dict.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (i == dict[""]) continue;
                if (isPalindrome(words[i])) ans.push_back({dict[""], i});
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);

                if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                    ans.push_back({i, dict[left]});
                }
                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                    ans.push_back({dict[right], i});
                }
            }
        }
        return ans;
    }
    bool isPalindrome(string str) {
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            if (str[i++] != str[j--]) return false;
        }
        return true;
    }

};