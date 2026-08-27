#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

/*
LC 3622 - Check Divisibility by Digit Sum and Product
https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/

Problem:
    You are given a positive integer n. Determine whether n is divisible by the
    sum of the following two values:
        - The digit sum of n (the sum of its digits).
        - The digit product of n (the product of its digits).
    Return true if n is divisible by this sum; otherwise, return false.

    Constraints:
        1 <= n <= 10^6

Examples:
    Input: n = 99
    Output: true
    Explanation: Since 99 is divisible by the sum (9 + 9 = 18) plus product
    (9 * 9 = 81) of its digits (total 99), the output is true.

    Input: n = 23
    Output: false
    Explanation: Since 23 is not divisible by the sum (2 + 3 = 5) plus product
    (2 * 3 = 6) of its digits (total 11), the output is false.

Best solution:
    Single linear scan of the decimal digits, accumulating the digit sum and the
    digit product in one pass, then one modulo test.

Time & Space complexity:
    Time:  O(log n) - the loop runs once per decimal digit of n, i.e. at most 7
           iterations for n <= 10^6.
    Space: O(1) - two integer accumulators, no digit buffer is materialised.

Approach (detail):
    1. Peel the digits off n from the least significant end: d = m % 10, then
       m /= 10, until m becomes 0. Digit order is irrelevant here because both a
       sum and a product are commutative, so no reversal or string conversion is
       needed.
    2. Maintain d_sum starting at 0 (identity for addition) and d_prod starting at
       1 (identity for multiplication), folding each peeled digit into both.
    3. Return n % (d_sum + d_prod) == 0.
    4. Why the divisor is never 0 (the only correctness trap): n >= 1, so n has at
       least one non-zero digit, hence d_sum >= 1. The product may well be 0 (any
       digit 0 zeroes it out, e.g. n = 105 -> d_prod = 0), but the sum term keeps
       d_sum + d_prod >= 1, so the modulo is always well defined.
    5. No overflow risk: with n <= 10^6 the digit sum is at most 7*9 = 63 and the
       digit product at most 9^7 = 4782969, both far inside int range.

Your solution:
    MATCHES BEST - the committed code is exactly this one-pass digit fold: it
    accumulates d_sum and d_prod in a single while loop over the digits of n and
    returns n % (d_sum + d_prod) == 0, running in O(log n) time and O(1) space,
    which is optimal since every digit of n must be read at least once.
*/

class Solution {
    public:
        bool checkDivisibility(int n) {
            int d_sum = 0, d_prod = 1;
            int m = n;
            while (m){
                int d = m % 10;
                d_sum += d;
                d_prod *= d;
                m /= 10;
            }
            return n % (d_sum + d_prod) == 0;
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