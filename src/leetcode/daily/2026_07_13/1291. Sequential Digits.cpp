#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * Best solution: Enumerate all sequential-digit numbers (fixed, tiny set).
 *   There are only 36 sequential-digit numbers total: for each length
 *   len in [2..9] and each starting digit s in [1..(10-len)] the number is
 *   s, s+1, ..., s+len-1 (e.g. len=3, s=1 -> 123). Keep those in [low, high].
 *
 * Time:  O(1)  — at most 36 candidates regardless of the input range.
 * Space: O(1)  — excluding the output vector.
 *
 * Approach (detail):
 *   1. A sequential-digit number is a contiguous run of increasing digits,
 *      so it is fully determined by (length, starting digit); only 36 exist.
 *   2. Restrict lengths to [digits(low), digits(high)] to skip candidates
 *      that cannot possibly lie in range.
 *   3. For a fixed length the smallest such number is start = 123..len, and
 *      the next one (same length, next starting digit) is start + offset,
 *      where offset = 111..1 (len ones): adding it bumps every digit by 1.
 *      Stop this length once the last digit would exceed 9 (num % 10 == 0).
 *   4. Push any candidate within [low, high]. They are produced in
 *      increasing order, so no final sort is needed.
 */
class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            int l = floor(log10(low))+1, h = floor(log10(high))+1;
            int start = 0, offset = 0;
            for (int d = 1; d <= l; ++d){
                start *= 10; start += d;
                offset *= 10; ++offset;
            }

            vector<int> res;
            for (int d, num, i = 0; i <= h - l; ++i){
                // cout << l << " " << start << " " << offset << " \n";
                num = start;
                while (num % 10){
                    if (num >= low && num <= high){
                        res.push_back(num);
                    }
                    num += offset;
                }

                d = start % 10 + 1;
                if (d == 10) break;
                start *= 10; start += d;
                offset *= 10; ++offset;
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