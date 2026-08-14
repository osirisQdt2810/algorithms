#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
    LC 2213 - Longest Substring of One Repeating Character
    https://leetcode.com/problems/longest-substring-of-one-repeating-character/

    Problem:
        You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of
        length k and a 0-indexed array of integer indices queryIndices of length k, both of which are
        used to describe k queries.
        The i-th query updates the character in s at index queryIndices[i] to the character
        queryCharacters[i].
        Return an array lengths of length k where lengths[i] is the length of the longest substring
        of s consisting of only one repeating character after the i-th query is performed.

        Constraints:
          - 1 <= s.length <= 10^5
          - s consists of lowercase English letters.
          - k == queryCharacters.length == queryIndices.length
          - 1 <= k <= 10^5
          - queryCharacters consists of lowercase English letters.
          - 0 <= queryIndices[i] < s.length

    Examples:
        Example 1:
            Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
            Output: [3,3,4]
            Explanation:
            - 1st query updates s = "bbbacc". The longest substring consisting of one repeating
              character is "bbb" with length 3.
            - 2nd query updates s = "bbbccc". The longest substring consisting of one repeating
              character can be "bbb" or "ccc" with length 3.
            - 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating
              character is "bbbb" with length 4.
            Thus, we return [3,3,4].

        Example 2:
            Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
            Output: [2,3]
            Explanation:
            - 1st query updates s = "abazz". The longest substring consisting of one repeating
              character is "zz" with length 2.
            - 2nd query updates s = "aaazz". The longest substring consisting of one repeating
              character is "aaa" with length 3.
            Thus, we return [2,3].

    Best solution:
        Segment tree over the string where each node stores a mergeable summary of its segment:
        the longest single-character run inside it, plus the longest run touching its left edge and
        the longest run touching its right edge, together with the boundary characters. Point update
        + read the root.

    Time & Space complexity:
        Time:  O(n + k log n)
               - the initial build visits each of the O(n) nodes once and merges in O(1); each of the
                 k point updates walks one root-to-leaf path of length O(log n), re-merging one node
                 per level.
        Space: O(n)
               - the tree stores O(4n) fixed-size nodes; no recursion deeper than O(log n).

    Approach (detail):
        1. The answer is not decomposable from lengths alone: the longest run in a segment can start
           in the left half and end in the right half. So each node must carry enough information to
           reconstruct cross-boundary runs. Store per node: max_len (best run fully inside), max_pref
           (run length starting at the segment's first index), max_suff (run length ending at its
           last index), and pref/suff (the characters at those two ends).
        2. Merge(left, right) for a node covering [l, r] with midpoint mid:
             - max_len starts as max(left.max_len, right.max_len);
             - pref = left.pref, suff = right.suff;
             - max_pref = left.max_pref, max_suff = right.max_suff.
           These are the values that hold when the two halves cannot join.
        3. The halves join exactly when left.suff == right.pref, i.e. the characters straddling the
           midpoint are equal. In that case:
             - a run spans the boundary with length left.max_suff + right.max_pref, so fold that into
               max_len;
             - if the left half is entirely one character (left.max_pref == mid - l + 1), the node's
               prefix run continues into the right half, so max_pref += right.max_pref;
             - symmetrically, if right.max_suff == r - mid, then max_suff += left.max_suff.
           These are the only ways a run can extend past a half, which is why the merge is complete.
        4. Build the tree bottom-up over s; a leaf has max_len = max_pref = max_suff = 1 and both
           boundary characters equal to its own.
        5. For query i, set position queryIndices[i] to queryCharacters[i] by descending to that
           leaf, rewriting its characters, and re-merging every node on the way back up. Only that
           one path can change, since every other node's children are untouched.
        6. After each update the root's max_len is the longest single-character run in the whole
           current string - append it to the answer.

    Your solution:
        MATCHES BEST - the code implements exactly the documented segment tree. `node` carries
        max_len / max_pref / max_suff / pref / suff, `update_it` is the merge from steps 2-3
        (including both "half is uniform" extensions guarded by the llen / rlen comparisons),
        `build` initialises leaves as in step 4, and `update(k, c)` rewrites one leaf and re-merges
        its ancestors, returning the root's max_len. Complexity is the documented O(n + k log n) time
        and O(n) space; the tree is 1-indexed, which is why the caller passes queryIndices[i] + 1.
*/

class Solution {
    private:
        struct node {
                int max_len{0};
                int max_pref{0}, max_suff{0};
                char pref{'|'};
                char suff{'|'};
        };

        struct segtree {
                int n;
                vector<node> nodes;

                void build(int t, int l, int r, string& input) {
                    // case 1: [l...r] k or k [l...r]
                    if (l > input.size()) return;
                    if (l == r) {
                        nodes[t].pref = nodes[t].suff = input[l - 1];
                        nodes[t].max_len = nodes[t].max_pref = nodes[t].max_suff = 1;
                        return;
                    }
                    int mid = (l + r) / 2;
                    build(2 * t, l, mid, input);
                    build(2 * t + 1, mid + 1, r, input);
                    update_it(t, l, r);
                }

                segtree(string& input) : n(input.size()), nodes(4 * n + 1) {
                    build(1, 1, n, input);
                }

                void update_it(int t, int l, int r) {
                    int mid = (l + r) / 2;
                    int llen = mid - l + 1;
                    int rlen = r - mid;

                    nodes[t].max_len = max(nodes[2 * t].max_len, nodes[2 * t + 1].max_len);
                    nodes[t].pref = nodes[2 * t].pref;
                    nodes[t].suff = nodes[2 * t + 1].suff;
                    nodes[t].max_pref = nodes[2 * t].max_pref;
                    nodes[t].max_suff = nodes[2 * t + 1].max_suff;

                    if (nodes[2 * t].suff == nodes[2 * t + 1].pref) {
                        nodes[t].max_len =
                            max(nodes[t].max_len, nodes[2 * t].max_suff + nodes[2 * t + 1].max_pref);
                        if (nodes[2 * t].max_pref == llen) {
                            nodes[t].max_pref += nodes[2 * t + 1].max_pref;
                        }
                        if (nodes[2 * t + 1].max_suff == rlen) {
                            nodes[t].max_suff += nodes[2 * t].max_suff;
                        }
                    }
                }

                int update(int t, int l, int r, int k, char c) {
                    // case 1: [l...r] k or k [l...r]
                    if (r < k || k < l) return nodes[t].max_len;
                    // case 2: [l...r] = k
                    if (l == r && l == k) {
                        nodes[t].pref = nodes[t].suff = c;
                        return nodes[t].max_len;
                    }
                    // case 3: k in [l...r]
                    int mid = (l + r) / 2;
                    int ml = update(2 * t, l, mid, k, c);
                    int mr = update(2 * t + 1, mid + 1, r, k, c);

                    // update nodes[t]
                    update_it(t, l, r);
                    return nodes[t].max_len;
                }

                int update(int k, char c) {
                    return update(1, 1, n, k, c);
                }
        };

    public:
        vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
            segtree tree(s);
            vector<int> res;
            for (int i = 0; i < (int)queryIndices.size(); ++i) {
                res.push_back(tree.update(queryIndices[i] + 1, queryCharacters[i]));
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
