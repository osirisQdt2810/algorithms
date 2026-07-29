#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * LC 3517 - Smallest Palindromic Rearrangement I
 *
 * Best solution: Counting sort over the first half of the palindrome, then
 * mirror it onto the second half. Optimal — the answer has length n so it must
 * be written in full, and this does O(n) work with only a fixed 26-slot tally.
 *
 * Time:  O(n + 26) = O(n) — one pass to tally the first n/2 characters, one
 *        pass over the 26 buckets emitting each counted character exactly once
 *        (inner while loops total n/2 writes), one pass to mirror.
 *        Comparison-sorting the half would be O(n log n) — strictly worse,
 *        since a fixed lowercase alphabet admits linear counting sort.
 * Space: O(26) = O(1) auxiliary — the frequency array only; the result is
 *        built by overwriting s in place rather than allocating a new buffer.
 *
 * Approach (detail):
 *   1. The input s is guaranteed to already be a palindrome. That is the key
 *      structural fact: a palindrome is fully determined by its first half
 *      plus (for odd n) its single middle character. So the multiset of the
 *      first half is exactly the pool we may permute, and the middle character
 *      — the one with odd count — is pinned at index m and can never move.
 *   2. Any rearrangement must stay a palindrome, so choosing the first half
 *      forces the second half. Lexicographic order is decided at the earliest
 *      differing index, and every index of the first half precedes every index
 *      of the second — therefore making the first half the lexicographically
 *      smallest permutation of its own multiset (i.e. sorted ascending) is
 *      globally optimal. No exchange argument is needed beyond that: sorted
 *      order minimizes each prefix position greedily.
 *   3. Let m = n / 2. Tally freqs[c] over s[0..m-1] only — deliberately
 *      excluding index m, which for odd n is the immovable middle character
 *      (for even n index m already belongs to the second half).
 *   4. Emit the sorted half: walk buckets c = 'a'..'z' and write each character
 *      freqs[c] times into s[0], s[1], ... This is counting sort; the writes
 *      stop exactly at index m-1 because the counts sum to m, so the middle
 *      character is left untouched.
 *   5. Mirror: for i = m..n-1 set s[i] = s[n-i-1]. For odd n the first
 *      iteration is i = m, where n-i-1 = m — a self-assignment that harmlessly
 *      preserves the middle character; subsequent iterations copy from the
 *      freshly sorted half. For even n the loop mirrors the whole second half.
 *   6. Return s, now the smallest palindromic rearrangement.
 */

class Solution {
    public:
        string smallestPalindrome(string s) {
            int n = s.size();
            int m = n / 2;
            vector<int> freqs(26);
            for (int i = 0; i < m; ++i){
                freqs[s[i]-'a']++;
            }

            for (int i = 0, j = 0; i < 26; ++i){
                while (freqs[i]){
                    s[j++] = 'a' + i;
                    --freqs[i];
                }
            }
            for (int i = m; i < n; ++i)
                s[i] = s[n-i-1];
            return s;
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