#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 1081 - Smallest Subsequence of Distinct Characters
 * (identical problem to LC 316 - Remove Duplicate Letters)
 *
 * Best solution: Greedy monotonic stack driven by last-occurrence indices.
 * This is optimal — the input must be read once, and each character enters and
 * leaves the stack at most once, giving a single amortized linear pass.
 *
 * Time:  O(n) — the outer loop is n iterations; the inner while loop pops, and
 *        every index is pushed exactly once and popped at most once, so total
 *        pop work is O(n) amortized. The last-occurrence precompute is another
 *        O(n).
 * Space: O(k) where k = alphabet size (26 here) — the stack holds distinct
 *        characters only, and `last` / `seen` are bounded by the alphabet. So
 *        O(1) auxiliary for a fixed alphabet, excluding the O(k) output.
 *
 * Approach (detail):
 *   1. Goal: pick each distinct character of s exactly once, keeping relative
 *      order, so the resulting string is lexicographically smallest.
 *   2. Precompute last[c] = the final index at which c occurs. This is the
 *      whole trick: it answers "if I drop c now, will I still get another
 *      chance to take it?"
 *   3. Sweep i = 0..n-1 with a monotonic (near-increasing) stack:
 *      a. If s[i] is already in the stack (`seen`), skip it — the character is
 *         accounted for, and re-adding would violate the distinctness rule.
 *         Crucially we must NOT pop anything to place a duplicate, because the
 *         copy already sitting in the stack is at an earlier position and
 *         therefore never worse.
 *      b. Otherwise, while the stack top is lexicographically greater than
 *         s[i] AND that top character reappears later (last[top] > i), pop it
 *         and clear it from `seen`. Dropping a bigger character from an
 *         earlier slot in favour of a smaller one strictly reduces the result
 *         at the most significant differing position — and the guard
 *         last[top] > i guarantees we can reinstate it further right, so
 *         completeness is preserved.
 *      c. Push i and mark s[i] seen.
 *   4. Why the greedy is correct: the stack is always a valid prefix of some
 *      complete answer, and at each step we make the leftmost position as
 *      small as it can possibly be without losing a required character. A
 *      lexicographic comparison is decided by the earliest difference, so
 *      locally minimizing the earliest mutable slot is globally optimal.
 *   5. Read the stack bottom-to-top (front-to-back of the deque) to build the
 *      answer.
 *
 * Note: the pop test is written `c <= s[dq.back()]`, but the `seen` skip in
 * step 3a means c can never equal the top, so `<=` behaves exactly as `<`.
 */

class Solution {
    public:
        string smallestSubsequence(string s) {
            // s = "bcabc" => "abc"
            // s = "cbacdcbc" => "acdbc", expect: "acdb"
            deque<int> dq;
            int n = s.size();
            unordered_map<char, int> last;
            unordered_set<char> seen;
            for (int i = 0; i < n; ++i){
                last[s[i]] = i;
            }

            for (int i = 0; i < n; ++i){
                char c = s[i];
                if (seen.find(c) != seen.end()) continue;
                while (!dq.empty() && c <= s[dq.back()] && last[s[dq.back()]] > i){
                    seen.erase(s[dq.back()]);
                    dq.pop_back();
                }
                dq.push_back(i);
                seen.insert(c);
            }

            string res = "";
            while (!dq.empty()){
                res += s[dq.front()];
                dq.pop_front();
            }
            return res;
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

    string s = "cbacdcbc";
    cout << sol.smallestSubsequence(s);

    return 0;
}