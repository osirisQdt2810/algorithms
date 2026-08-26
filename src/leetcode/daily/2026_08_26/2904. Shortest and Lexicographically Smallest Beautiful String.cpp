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
LC 2904 - Shortest and Lexicographically Smallest Beautiful String
https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

Problem:
    You are given a binary string s and a positive integer k. A substring of s is
    beautiful if the number of 1's in it is exactly k. Let len be the length of
    the shortest beautiful substring. Return the lexicographically smallest
    beautiful substring of s with length equal to len. If s doesn't contain a
    beautiful substring, return an empty string.

    A string a is lexicographically larger than a string b (of the same length) if
    in the first position where a and b differ, a has a character strictly larger
    than the corresponding character in b.

    Constraints:
        1 <= s.length <= 100
        1 <= k <= s.length

Examples:
    Input: s = "100011001", k = 3
    Output: "11001"
    Explanation: There are 7 beautiful substrings in this example. The length of
    the shortest beautiful substring is 5. The lexicographically smallest
    beautiful substring with length 5 is the substring "11001".

    Input: s = "1011", k = 2
    Output: "11"
    Explanation: There are 3 beautiful substrings in this example. The length of
    the shortest beautiful substring is 2. The lexicographically smallest
    beautiful substring with length 2 is the substring "11".

    Input: s = "000", k = 1
    Output: ""
    Explanation: There are no beautiful substrings in this example.

Best solution:
    Single sliding window over s that keeps exactly k ones and is kept minimal at
    both ends, tracking the best (shortest, then lexicographically smallest)
    candidate as it slides.

Time & Space complexity:
    Time:  O(n * len) - each of l and r advances at most n times, so O(n) windows
           are produced, and each tie on length costs an O(len) string compare.
    Space: O(len) - only the current candidate and the best answer are stored.

Approach (detail):
    1. Key structural insight: an optimal answer never starts or ends with '0'.
       Stripping a leading or trailing zero leaves the count of ones unchanged but
       makes the substring strictly shorter, so any window with a zero at either
       end is dominated. Therefore it suffices to consider windows that begin and
       end at a '1'.
    2. Slide r from left to right, adding s[r] to the running count of ones. After
       each step, shrink from the left while either the window carries more than k
       ones (too many - it can never be beautiful until ones are dropped) or the
       leftmost character is '0' (dominated by step 1). Both conditions are
       monotone in l, so l only ever moves forward and the total work stays linear.
    3. After shrinking, if the count of ones equals exactly k, the window [l, r] is
       the shortest beautiful window ending at r: l sits on the k-th one counted
       backwards from r, and any smaller l would either add a leading zero or a
       (k+1)-th one.
    4. Compare that candidate against the best so far: strictly shorter always
       wins; equal length falls back to a lexicographic string compare. Same-length
       comparison is exactly the ordering the problem defines, so a plain
       operator< on the substrings is correct.
    5. Initialise the best length to a sentinel above n (here via r_ans = 1e9) and
       the best string to "", so the empty string is returned untouched when no
       window ever reaches k ones - which is precisely the "no beautiful substring"
       case.

Your solution:
    MATCHES BEST - the committed code is this exact linear sliding window: it
    grows r, shrinks l while (s[l] == '0' || cnt_one > k), and on cnt_one == k
    updates the answer by shorter-length-then-lexicographic comparison, giving
    O(n * len) time and O(len) space, which is optimal since every character must
    be examined. The one dead branch worth noting is that windows ending in '0'
    can still be recorded, but they are always strictly longer than the
    already-seen window ending at the previous '1', so they can never displace the
    optimum.
*/

class Solution {
    public:
        string shortestBeautifulSubstring(string s, int k) {
            int n = s.size();
            int l_ans = 0, r_ans = 1e9;
            string ans = "";

            int cnt_one = 0;
            for (int l = 0, r = 0; r < n; ++r){
                cnt_one += s[r] == '1';
                while (s[l] == '0' || cnt_one > k){
                    cnt_one -= s[l] == '1';
                    ++l;
                }

                if (cnt_one == k){
                    int len = r - l + 1;
                    int len_ans = r_ans - l_ans + 1;
                    if (len < len_ans){
                        l_ans = l;
                        r_ans = r;
                        ans = s.substr(l, len);
                    }
                    else if (len == len_ans){
                        string sub = s.substr(l, len);
                        if (sub < ans){
                            l_ans = l;
                            r_ans = r;
                            ans = sub;
                        }
                    }

                    // cout << "l=" << l << " r=" << r << " len=" << len << "\n";
                }
            }
            return ans;
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