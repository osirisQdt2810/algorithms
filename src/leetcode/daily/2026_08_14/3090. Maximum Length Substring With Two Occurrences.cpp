#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

/*
    LC 3090 - Maximum Length Substring With Two Occurrences
    https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/

    Problem:
        Given a string s, return the maximum length of a substring such that it contains at most two
        occurrences of each character.

        Constraints:
          - 2 <= s.length <= 100
          - s consists only of lowercase English letters.

    Examples:
        Example 1:
            Input: s = "bcbbbcba"
            Output: 4
            Explanation:
            The following substring has a length of 4 and contains at most two occurrences of each
            character: "bcbbbcba".

        Example 2:
            Input: s = "aaaa"
            Output: 2
            Explanation:
            The following substring has a length of 2 and contains at most two occurrences of each
            character: "aaaa".

    Best solution:
        Sliding window (two pointers) with a 26-slot character frequency counter.

    Time & Space complexity:
        Time:  O(n)
               - the right pointer advances n times and the left pointer only ever moves forward, so
                 the two together perform at most 2n counter updates.
        Space: O(1)
               - at most 26 counters, one per lowercase letter, independent of n.

    Approach (detail):
        1. Maintain a window [l, r] plus a frequency table of the characters inside it, keeping the
           invariant "no character occurs more than twice in the window" true at the end of every
           iteration.
        2. Extend the window one character to the right: ++freqs[s[r]].
        3. Only s[r]'s count changed, so the invariant can only have been broken for s[r]. Shrink
           from the left while freqs[s[r]] > 2, decrementing freqs[s[l]] and advancing l. This
           terminates because l eventually passes an earlier occurrence of s[r], dropping its count
           back to 2.
        4. The window is now valid, so update res = max(res, r - l + 1).
        5. Why this is optimal: the constraint is monotone under taking substrings - any substring of
           a valid window is valid - so for each right end r the set of feasible left ends is a
           suffix of [0, r], and its smallest element is non-decreasing as r grows. The sweep keeps l
           at exactly that smallest feasible position, so it evaluates the longest valid substring
           ending at every r, and the maximum over all r is the answer.

    Your solution:
        MATCHES BEST - the code is the documented O(n) sliding window: grow at r, shrink from l only
        while the just-incremented freqs[s[r]] exceeds 2, then take the running maximum of the window
        length. It uses an unordered_map rather than a fixed 26-element array, so space is O(1) in the
        same sense (bounded by the 26 possible keys) with slightly worse constants - no complexity
        difference.
*/

class Solution {
    public:
        int maximumLengthSubstring(string s) {
            int n = s.size(), res = 0;
            unordered_map<char, int> freqs;
            for (int l = 0, r = 0; r < n; ++r) {
                ++freqs[s[r]];
                while (freqs[s[r]] > 2) {
                    --freqs[s[l]];
                    ++l;
                }
                res = max(res, r - l + 1);
            }
            return res;
        }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main() {
    Solution sol;

    return 0;
}
