#include <vector>
#include <iostream>

using namespace std;

/*
LC 5 - Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

Problem:
    Given a string s, return the longest palindromic substring in s.

    Constraints:
        1 <= s.length <= 1000
        s consist of only digits and English letters.

Examples:
    Input:  s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

    Input:  s = "cbbd"
    Output: "bb"

Best solution:
    Manacher's algorithm (linear-time palindromic radius scan).

Time & Space complexity:
    Time:  O(n) - the right boundary of the rightmost known palindrome only ever moves
           forward, so the total work of all boundary extensions is amortized linear.
    Space: O(n) - one radius array over the 2n+1 centers.

Approach (detail):
    1. Handle even-length palindromes by working over the 2n+1 virtual centers (each
       character and each gap), or equivalently by interleaving a sentinel: t = "#a#b#a#".
       Every palindrome of s maps to an odd-length palindrome of t, so a single
       odd-center scan suffices.
    2. Keep p[i] = radius of the longest palindrome centered at i in t, plus (c, r): the
       center and right end of the rightmost-reaching palindrome found so far.
    3. For each i < r, let mirror = 2*c - i. The palindrome around c is symmetric, so the
       palindrome at mirror is mirrored into i and gives a free lower bound:
       p[i] = min(p[mirror], r - i). That bound is what makes the algorithm linear - the
       mirror is only trusted up to the enclosing palindrome's edge, beyond which the
       symmetry argument no longer applies.
    4. Extend p[i] character by character past that bound while t[i-p[i]-1] == t[i+p[i]+1].
       Each such extension pushes i + p[i] beyond the old r, so extensions are paid for by
       the monotone advance of r: O(n) total across all centers.
    5. If i + p[i] > r, update (c, r) = (i, i + p[i]).
    6. The answer is the center with maximum p[i]; p[i] is exactly the palindrome's length
       in s, and its start index in s is (i - p[i]) / 2.

Your solution:
    SUBOPTIMAL - the code runs expand-around-center, not Manacher: for every index it calls
    expand() and walks outward while the two characters match, giving Time O(n^2) (a
    palindromic string like "aaaa..." makes every center extend ~n/2 steps) and Space O(1).
    The gap is O(n^2) vs O(n): it re-derives from scratch at each center the palindrome
    information Manacher carries forward in p[]. It still passes comfortably because
    n <= 1000, so the worst case is on the order of 10^6 character comparisons. The
    correctness is fine: expand(s, center) tries all three seeds - the odd center (l = r =
    center) and both even seeds (center-1, center) and (center, center+1) - so both parities
    are covered, and expand(s, l, r) returns {l+1, r-1}, the last matching pair before the
    loop broke.
*/

class Solution {
    private:
        using ii = pair<int, int>;
        ii expand(string& s, int l, int r){
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                --l;
                ++r;
            }
            return {l+1, r-1};
        }
        ii expand(string& s, int center){
            // case 1:
            int l = center, r = center;
            auto [l1, r1] = expand(s, l, r);

            // case 2:
            if (center > 0 && s[center-1] == s[center]){
                l = center - 1;
                r = center;
                auto [l2, r2] = expand(s, l, r);
                if (r2 - l2 + 1 > r1 - l1 + 1){
                    l1 = l2;
                    r1 = r2;
                }
            }

            // case 3:
            if (center + 1 < s.size() && s[center] == s[center+1]){
                l = center;
                r = center+1;
                auto [l3, r3] = expand(s, l, r);
                if (r3 - l3 + 1 > r1 - l1 + 1){
                    l1 = l3;
                    r1 = r3;
                }
            }

            return {l1, r1};
        }

    public:
        string longestPalindrome(string s) {
            int n = s.size();   // babad

            struct Answer {
                int l{0};
                int r{0};

                int len() const {
                    return r-l+1;
                }
            };

            Answer ans;
            for (int i = 0; i < n; ++i){
                auto [l, r] = expand(s, i);
                if (ans.len() < r-l+1){
                    ans = {l, r};
                }
            }
            return s.substr(ans.l, ans.len());
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

    // h[1] h[2] h[3] h[4] h[5] h[6]
    // (l r) => min(h[l], h[r]) * (r-l)
    return 0;
}