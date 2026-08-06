#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3016 - Minimum Number of Pushes to Type Word II
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
 *
 * Problem:
 *   You are given a string word containing lowercase English letters.
 *
 *   Telephone keypads have keys mapped with distinct collections of lowercase
 *   English letters, which can be used to form words by pushing them. For
 *   example, the key 2 is mapped with ["a","b","c"], we need to push the key
 *   one time to type "a", two times to type "b", and three times to type "c".
 *
 *   It is allowed to remap the keys numbered 2 to 9 to distinct collections of
 *   letters. The keys can be remapped to any amount of letters, but each letter
 *   must be mapped to exactly one key. You need to find the minimum number of
 *   times the keys will be pushed to type the string word.
 *
 *   Return the minimum number of pushes needed to type word after remapping the
 *   keys. Note that 1, *, #, and 0 do not map to any letters.
 *
 *   Constraints:
 *     - 1 <= word.length <= 10^5
 *     - word consists of lowercase English letters.
 *
 * Examples:
 *   Example 1:
 *     Input:  word = "abcde"
 *     Output: 5
 *     Explanation: "a".."e" each get one push on keys 2..6.
 *       Total cost is 1 + 1 + 1 + 1 + 1 = 5.
 *
 *   Example 2:
 *     Input:  word = "xyzxyzxyzxyz"
 *     Output: 12
 *     Explanation: "x" -> one push on key 2, "y" -> one push on key 3,
 *       "z" -> one push on key 4. Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12.
 *       Note that the key 9 is not mapped to any letter: it is not necessary to
 *       map letters to every key, but to map all the letters.
 *
 *   Example 3:
 *     Input:  word = "aabbccddeeffgghhiiiiii"
 *     Output: 24
 *     Explanation: "a".."g" -> one push on keys 2..8, "h" -> two pushes on key
 *       9, "i" -> one push on key 9.
 *       Total cost is 1*2 + 1*2 + 1*2 + 1*2 + 1*2 + 1*2 + 1*2 + 2*2 + 6*1 = 24.
 *
 * Best solution: Frequency count + sort descending + greedy assignment in
 * rounds of 8 (a rearrangement-inequality / exchange-argument greedy).
 *
 * Time:  O(n + K log K) with K = 26, i.e. effectively O(n) — one pass to count,
 *        then a sort of a fixed 26-element array. Counting sort on the
 *        frequencies would make it strictly O(n).
 * Space: O(K) = O(1) — a fixed 26-slot frequency array.
 *
 * Approach (detail):
 *   1. Cost model: assigning a letter to slot position p (1-indexed) on a key
 *      makes each *occurrence* of that letter cost p pushes. So a letter with
 *      frequency f placed at position p contributes f * p, and the total is
 *      sum over letters of freq[c] * pos[c].
 *   2. With 8 usable keys (2..9), the multiset of available positions is: eight
 *      slots of cost 1, eight of cost 2, eight of cost 3, and so on. At most 26
 *      distinct letters exist, so costs never exceed 4.
 *   3. Minimizing sum(freq[c] * pos[c]) over all assignments is a pairing
 *      problem between the frequency multiset and the position multiset. By the
 *      rearrangement inequality, the sum is minimized when the two sequences are
 *      oppositely ordered: the largest frequency takes the smallest position.
 *      Exchange argument: if f1 > f2 but p1 > p2, swapping them changes the
 *      total by (f1 - f2)(p2 - p1) < 0, a strict improvement — so any non-sorted
 *      pairing is suboptimal.
 *   4. Implementation: tally freq[26] over word, sort descending, then walk the
 *      letters assigning cost `times`, starting at 1 and incrementing after
 *      every 8 letters consumed (tracked by the `counter` countdown from 8).
 *      Accumulate times * freq[i].
 *   5. Break as soon as a zero frequency is hit — the array is sorted
 *      descending, so all remaining letters are absent from word and cost
 *      nothing. (Letters not in word need not be mapped cheaply, or at all.)
 *   6. This generalizes LC 3014: there every frequency is 1, so the sum
 *      collapses to counting positions only and the sort becomes unnecessary.
 */

class Solution {
    public:
        int minimumPushes(string word) {
            const int kAlphabet = 26;
            vector<int> letters(kAlphabet, 0);
            for (auto& c : word){
                ++letters[c - 'a'];
            }
            sort(letters.begin(), letters.end(), greater<int>());

            int pushes = 0, times = 1, counter = 8;
            for (int i = 0; i < kAlphabet; ++i){
                if (!letters[i]) break;
                int f = letters[i];
                pushes += times * f;
                if (--counter == 0){
                    counter = 8;
                    ++times;
                }
            }
            return pushes;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;

    return 0;
}