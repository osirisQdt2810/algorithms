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
LC 3116 - Kth Smallest Amount With Single Denomination Combination
https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/

Problem:
    You are given an integer array coins representing coins of different
    denominations and an integer k. You have an infinite number of coins of each
    denomination. However, you are not allowed to combine coins of different
    denominations.
    Return the k-th smallest amount that can be made using these coins.

    Constraints:
        1 <= coins.length <= 15
        1 <= coins[i] <= 25
        1 <= k <= 2 * 10^9
        coins contains pairwise distinct integers.

Examples:
    Input: coins = [3,6,9], k = 3
    Output: 9
    Explanation: Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc. Coin 6
    produces 6, 12, 18, 24, etc. Coin 9 produces 9, 18, 27, 36, etc. All of the
    coins combined produce: 3, 6, 9, 12, 15, etc.

    Input: coins = [5,2], k = 7
    Output: 12
    Explanation: Coin 5 produces 5, 10, 15, 20, etc. Coin 2 produces 2, 4, 6, 8,
    10, 12, etc. All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14,
    15, etc.

Best solution:
    Binary search on the answer, with the count of reachable amounts <= X
    evaluated by inclusion-exclusion over all coin subsets via their LCM.

Time & Space complexity:
    Time:  O(2^n * n * log(k * maxCoin)) - each binary-search step enumerates all
           2^n subsets and folds n LCMs; n <= 15 and the answer is <= k*25.
    Space: O(n) - only the (optionally reduced) coin list and O(1) scratch.

Approach (detail):
    1. Because denominations cannot be mixed, coin c reaches exactly the multiples
       of c. So the set of reachable amounts is the union over c of the multiples
       of c, and it is monotone: if X is counted, every value below it is settled
       too. That monotonicity is what makes binary search on the answer valid.
    2. Define f(X) = how many reachable amounts are <= X. The answer is the
       smallest X with f(X) >= k, so binary search X over [1, k * max(coins)] and
       keep the first X that satisfies the predicate.
    3. Compute f(X) by inclusion-exclusion over the coins. For a subset S, the
       amounts <= X divisible by every coin in S number exactly X / lcm(S). Then
       f(X) = sum over non-empty S of (-1)^(|S|+1) * (X / lcm(S)): odd-sized
       subsets add, even-sized subsets subtract. This is the standard count of
       "divisible by at least one" and is exact, not an estimate.
    4. Fold lcm(S) incrementally as lcm(a, b) = a / gcd(a, b) * b, and stop early
       once the running LCM exceeds X - beyond that point X / lcm is 0 and the term
       cannot change the sum.
    5. Optional pruning: if coin a divides coin b, every multiple of b is already a
       multiple of a, so b contributes nothing to the union and can be dropped.
       Sorting ascending and keeping a coin only when no kept coin divides it
       shrinks n and therefore the 2^n factor.
    6. No overflow: coins are <= 25, so lcm over any subset is at most
       lcm(1..25) = 26771144400 (about 2.7e10), and the folding product stays well
       inside 64 bits.

Your solution:
    MATCHES BEST - the code is exactly this algorithm: filter_redundant_coins does
    the divisibility pruning of step 5, subset() is the inclusion-exclusion sum of
    step 3 with the early LCM cutoff of step 4, and findKthSmallest binary searches
    the predicate subset(coins, m) >= k. Time O(2^n * n * log R), Space O(n).
    The early `break` leaves bit_count and curr_lcm partial, but the term added
    afterwards is X / curr_lcm with curr_lcm > X, which is 0 under integer
    division, so the parity of the truncated subset cannot corrupt the sum.
*/

class Solution {
    private:
        // gcd(X, Y) = gcd(Y, X-Y) (3, 5) = ()
        long long gcd(long long X, long long Y){
            return (Y == 0) ? X : gcd(Y, X % Y);
        }

        long long lcm(long long X, long long Y){
            return (X * Y / gcd(X, Y));
        }

        // how many numbers N <= X where N is divisible coin c in coins
        long long subset(vector<int>& coins, long long X){
            long long res = 0;
            int n = coins.size();   //
            for (int mask = 1; mask < (1 << n); ++mask){    //
                long long curr_lcm = 1;
                int bit_count = 0;
                for (int i = 0; i < n; ++i){
                    if (mask & (1 << i)){   // coins[i] in list
                        bit_count++;
                        curr_lcm = lcm(curr_lcm, coins[i]);
                        if (curr_lcm > X) break;
                    }
                }
                if (bit_count % 2){
                    res += X / curr_lcm;
                }
                else {
                    res -= X / curr_lcm;
                }
            }
            return res;
        }

        vector<int> filter_redundant_coins(vector<int>& coins){
            vector<int> res;
            sort(coins.begin(), coins.end());
            for (auto coin : coins){
                bool is_invalid = false;
                for (auto r : res){
                    if (coin % r == 0){
                        is_invalid = true;
                        break;
                    }
                }
                if (!is_invalid){
                    res.push_back(coin);
                }
            }
            return res;
        }

    public:
        long long findKthSmallest(vector<int>& coins, int k) {
            // filter coin
            coins = filter_redundant_coins(coins);

            long long l = 1, r = 4e18, ans = -1;
            while (l <= r){
                long long m = (l+r)/2;
                if (subset(coins, m) >= k){
                    ans = m;
                    r = m-1;
                }
                else {
                    l = m+1;
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