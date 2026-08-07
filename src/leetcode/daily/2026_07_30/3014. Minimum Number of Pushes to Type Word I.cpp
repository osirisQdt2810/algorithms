#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3014 - Minimum Number of Pushes to Type Word I
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 *
 * Problem:
 *   You are given a string word containing distinct lowercase English letters.
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
 *     - 1 <= word.length <= 26
 *     - word consists of lowercase English letters.
 *     - All letters in word are distinct.
 *
 * Examples:
 *   Example 1:
 *     Input:  word = "abcde"
 *     Output: 5
 *     Explanation: "a" -> one push on key 2, "b" -> one push on key 3,
 *       "c" -> one push on key 4, "d" -> one push on key 5,
 *       "e" -> one push on key 6. Total cost is 1 + 1 + 1 + 1 + 1 = 5.
 *
 *   Example 2:
 *     Input:  word = "xycdefghij"
 *     Output: 12
 *     Explanation: "x" -> one push on key 2, "y" -> two pushes on key 2,
 *       "c" -> one push on key 3, "d" -> two pushes on key 3, and "e".."j" ->
 *       one push each on keys 4..9.
 *       Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
 *
 * Best solution: Closed-form greedy — fill the 8 keys in rounds, every letter
 * in round t costs t pushes. Because all letters are distinct, each appears
 * exactly once and no frequency counting is needed at all.
 *
 * Time:  O(1) — word has at most 26 distinct letters, so the loop runs at most
 *        ceil(26/8) = 4 iterations regardless of input.
 * Space: O(1) — only two integer accumulators.
 *
 * Approach (detail):
 *   1. Cost model: if a letter is placed at slot position p (1-indexed) on a
 *      key, typing it once costs p pushes. There are 8 usable keys (2..9), so
 *      the multiset of achievable per-letter costs is: eight letters at cost 1,
 *      the next eight at cost 2, the next eight at cost 3, and so on.
 *   2. Since every letter of word is distinct, each letter is typed exactly
 *      once, so total cost = sum of the per-letter costs. Minimizing a sum of
 *      n values drawn from that multiset means greedily taking the n cheapest
 *      slots: fill all eight cost-1 slots first, then all eight cost-2 slots,
 *      etc. An exchange argument confirms optimality — if any cost-2 slot were
 *      used while a cost-1 slot sat empty, moving that letter down strictly
 *      lowers the total.
 *   3. So with n = word.size(), walk rounds t = 1, 2, 3, ...: the current round
 *      absorbs min(8, n) still-unassigned letters, each costing t, so add
 *      t * min(8, n) to the answer and subtract 8 from n.
 *   4. Stop when n <= 0. Every letter has been charged its greedy-minimal cost,
 *      so the accumulated total is the optimum.
 *   5. Note the distinctness constraint is what makes this input-independent:
 *      only the *length* of word matters, never which letters it holds. (The
 *      general, repeated-letter version is LC 3016.)
 */

class Solution {
    public:
        int minimumPushes(string word) {
            int n = word.size();
            int pushes = 0, times = 1;
            while (n > 0){
                pushes += times * min(8, n);
                ++times;
                n -= 8;
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