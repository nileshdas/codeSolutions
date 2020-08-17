// Design an Iterator class, which has:

// A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a next combination.


// Example:

// CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

// iterator.next(); // returns "ab"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "ac"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "bc"
// iterator.hasNext(); // returns false


// Constraints:

// 1 <= combinationLength <= characters.length <= 15
// There will be at most 10^4 function calls per test.
// It's guaranteed that all calls of the function next are valid.

class CombinationIterator {
public:
    vector<bool> combo; // index in chars -> true if chars[i] is a part of the next combination
    bool hasNextBool;
    string chars;
    int n; // combination length

    CombinationIterator(string characters, int combinationLength) {
        chars = characters;
        n = combinationLength;
        combo.resize(chars.size());
        for (int i = 0; i < n; i++) combo[i] = true; // first n symbols - 1st combo
        hasNextBool = chars.size() >= n; // if we have enough chars for at least one combination
    }

    string next() {
        string res = "";
        for (int i = 0; i < combo.size(); i++)
            if (combo[i])
                res += chars[i];
        hasNextBool = prev_permutation(begin(combo), end(combo)); // get ready for the next iteration
        return res;
    }

    bool hasNext() {
        return hasNextBool;
    }
};