#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

/*
 * Best solution: Closed-form O(1) math.
 *   sumOdd  = 1 + 3 + ... + (2n-1) = n^2
 *   sumEven = 2 + 4 + ... + 2n     = n(n+1) = n^2 + n
 *   gcd(n^2, n^2 + n) = gcd(n^2, n) = n  (since n divides n^2),
 *   so the answer is simply n.
 *
 * Time:  O(1)  — constant arithmetic, no loop.
 * Space: O(1).
 *
 * Approach (detail):
 *   1. The sum of the first n odd numbers is the perfect square n^2.
 *   2. The sum of the first n even numbers is n(n+1) = n^2 + n.
 *   3. gcd(n^2, n^2 + n) = gcd(n^2, (n^2 + n) - n^2) = gcd(n^2, n) = n,
 *      because n is a divisor of n^2. Hence gcd(sumOdd, sumEven) = n.
 *   4. Return n directly — no need to compute the sums or run Euclid.
 */
class Solution {
    public:
        int gcdOfOddEvenSums(int n) {
            return n;
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