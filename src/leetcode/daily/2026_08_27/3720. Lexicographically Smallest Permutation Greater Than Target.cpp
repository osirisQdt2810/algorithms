#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/*
LC 3720 - Lexicographically Smallest Permutation Greater Than Target
https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/

Problem:
    You are given two strings s and target, both having length n, consisting of
    lowercase English letters.

    Return the lexicographically smallest permutation of s that is strictly
    greater than target. If no permutation of s is lexicographically strictly
    greater than target, return an empty string.

    A string a is lexicographically strictly greater than a string b (of the same
    length) if in the first position where a and b differ, string a has a letter
    that appears later in the alphabet than the corresponding letter in b.

    Constraints:
        1 <= s.length == target.length <= 300
        s and target consist of only lowercase English letters.

Examples:
    Input: s = "abc", target = "bba"
    Output: "bca"
    Explanation: The permutations of s in lexicographical order are "abc", "acb",
    "bac", "bca", "cab", "cba"; the smallest one strictly greater than target is
    "bca".

    Input: s = "leet", target = "code"
    Output: "eelt"
    Explanation: "eelt" is the smallest permutation of s, and it is already
    strictly greater than "code".

    Input: s = "baba", target = "bbaa"
    Output: ""
    Explanation: The permutations of s are "aabb", "abab", "abba", "baab", "baba"
    and "bbaa"; none is strictly greater than target.

Best solution:
    Greedy over the split position: find the *latest* index at which the answer can
    first exceed target, then fill the tail with the leftover letters in ascending
    order.

Time & Space complexity:
    Time:  O(26n) - one left-to-right pass over the n positions, each scanning the
           26-letter alphabet once, plus an O(n + 26) reconstruction.
    Space: O(26) - a single count array of the multiset of letters of s (the output
           string itself is not counted).

Approach (detail):
    1. Any answer strictly greater than target has a well-defined split index i:
       it agrees with target on positions 0..i-1 and carries a letter strictly
       greater than target[i] at position i. Everything after i is then free, and
       to minimise the answer it must be the remaining letters sorted ascending.
    2. A larger split index always beats a smaller one. Comparing a candidate that
       splits at i with one that splits at j > i, both agree on 0..i-1, and at
       position i the first holds a letter > target[i] while the second holds
       exactly target[i]. So the later split is strictly smaller, and the goal is
       the *maximum* feasible split index.
    3. Feasibility of split index i needs two things from the multiset of s: the
       letters target[0..i-1] must all be available to build the matching prefix,
       and after removing them some letter strictly greater than target[i] must
       remain.
    4. Sweep i upward maintaining curr_letters, the counts left after consuming
       target[0..i-1]. At each i, look for the smallest available letter above
       target[i]; if one exists, record (i, that letter), overwriting any earlier
       record - so the last record kept is the maximum feasible split.
       Then consume target[i] to move on; if target[i] is unavailable, no longer
       prefix can be matched and the sweep stops.
    5. If no split was ever recorded, every permutation of s is <= target (the only
       remaining possibility is a permutation equal to target, which is not
       strictly greater), so return "".
    6. Reconstruct: emit target[0..i-1], then the recorded split letter, decrementing
       each from the counts, then emit all remaining letters from 'a' to 'z' in
       order, which is the smallest arrangement of the free tail.

Your solution:
    MATCHES BEST - the committed code performs exactly this greedy sweep, keeping
    the last (hence maximum) feasible split index and its smallest exceeding
    letter, then rebuilding prefix + split letter + sorted remainder, at O(26n)
    time and O(26) space.
*/

class Solution {
    public:
        string lexGreaterPermutation(string s, string target) {
            vector<int> letters(26, 0);
            for (auto& c : s){
                ++letters[c-'a'];
            }
            vector<int> curr_letters = letters;

            int best_split_idx = -1;
            char best_split_char = '|';

            int n = s.size();
            for (int i = 0; i < n; ++i){
                int d = target[i] - 'a';

                for (int j = d + 1; j < 26; ++j){
                    if (curr_letters[j]){
                        best_split_idx = i;
                        best_split_char = (char)('a' + j);
                        break;
                    }
                }

                if (curr_letters[d]){
                    --curr_letters[d];
                }
                else {

                    break;
                }
            }

            if (best_split_idx == -1) return "";

            string res = "";
            for (int i = 0; i < best_split_idx; ++i){
                res += target[i];
                --letters[target[i]-'a'];
            }
            res += best_split_char; --letters[best_split_char-'a'];
            for (int i = 0; i < 26; ++i){
                while (letters[i] > 0){
                    res += (char)('a' + i);
                    --letters[i];
                }
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

    return 0;
}