// A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

// Given three integers a, b and c, return any string s, which satisfies following conditions:

// s is happy and longest possible.
// s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
// s will only contain 'a', 'b' and 'c' letters.
// If there is no such string s return the empty string "".



// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
// Example 2:

// Input: a = 2, b = 2, c = 1
// Output: "aabbc"
// Example 3:

// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It's the only correct answer in this case.


// Constraints:

// 0 <= a, b, c <= 100
// a + b + c > 0


class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a != 0) pq.push({ a, 'a' });
        if (b != 0) pq.push({ b, 'b' });
        if (c != 0) pq.push({ c, 'c' });
        char prev1 = '#';
        char prev2 = '#';
        string res;
        while (!pq.empty())
        {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            if (ch1 == prev1 && ch1 == prev2)
            {
                if (pq.empty()) return res;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                prev1 = prev2;
                prev2 = ch2;
                pq.push({ cnt1, ch1 });
                if (--cnt2 > 0) pq.push({ cnt2, ch2 });
            }
            else
            {
                prev1 = prev2;
                prev2 = ch1;
                res += ch1;
                if (--cnt1 > 0) pq.push({ cnt1, ch1 });
            }
        }
        return res;
    }
};