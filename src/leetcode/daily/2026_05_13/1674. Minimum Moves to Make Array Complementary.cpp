#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <map>

using namespace std;

class Solution {
    public:
        // O(n * L)
        int minMovesBruteforce(vector<int>& nums, int limit){
            // for all t, we need to find the minimum moves to make all pair (nums[i], nums[n-i-1]) have sum t
            int n = nums.size();
            int ans = INT_MAX;
            for (int s = 2; s <= 2 * limit + 2; ++s){
                // find the minimum moves to have T = nums[i] + nums[n-i-1] = s
                // call: a = min(nums[i], nums[n-i-1]), b = max(nums[i], nums[n-i-1])
                // if: a + b = s => 0 moves
                // to achive 1 move: we need to move a or b. Additionally, we have:
                //      T in [min + 1, min + limit] &&
                //      T in [max + 1, max + limit]
                // therefore, if s in [min + 1, max + limit], we can achive sum by 1 move
                // other wise: s < min + 1 || s > max + limit => achieve sum by 2 moves
                int moves = 0;
                for (int i = 0; i < n / 2; ++i){
                    int a = min(nums[i], nums[n-i-1]);
                    int b = max(nums[i], nums[n-i-1]);
                    if (a + b == s) continue;
                    if (s >= a + 1 && s <= b + limit) ++moves;
                    else moves += 2;
                }
                ans = min(ans, moves);
            }
            return ans;
        }


        // O(log(n) * L)
        int minMovesBinarySearch(vector<int>& nums, int limit){
            // still uses the same pattern as brute-force
            // but we find i such that s in [min(nums[i], nums[n-i-1]) + 1, max(nums[i], nums[n-i-1]) + limit] by binary search
            // we can modelize this problem as:
            //     - we have an array of pairs (c, d): [c1, d1], [c2, d2], ..., [c_n, d_n], where c_i < d_i
            //     - for fixed s, we want to find the number of pairs (c_i, d_i) such that c_i <= s <= d_i
            //     -> this is sweep line problem.
            // solution:
            //    - we can sort increase the pairs by c_i, and we can also sort increase the pairs by d_i
            //    - the target number of pairs (c_i, d_i) such that: c_i <= s <= d_i = n - count(s < c_i) - count(s > d_i)
            auto count_sweepline = [&](const vector<int>& c, const vector<int>& d, int s) -> pair<int, int> {
                int n = c.size();
                int lc = 0, rc = n - 1, ic=n;
                // find ic min that c[ic] > s => count(s < c_i) = [ic -> n - 1]
                while (lc <= rc){
                    int m = (lc + rc) / 2;
                    if (c[m] > s){
                        ic = m;
                        rc = m - 1;
                    }
                    else {
                        lc = m + 1;
                    }
                }
                int cnt_c = n - ic;
                int ld = 0, rd = n - 1, id = -1;
                // find id max that d[id] < s => count(s > d_i) [0 -> id]
                while (ld <= rd){
                    int m = (ld + rd) / 2;
                    if (d[m] < s){
                        id = m;
                        ld = m + 1;
                    }
                    else {
                        rd = m - 1;
                    }
                }
                int cnt_d = id + 1;
                return {n - cnt_c - cnt_d, cnt_c + cnt_d};
            };

            unordered_map<int, int> count_sum;
            vector<int> arr_c, arr_d;
            int n = nums.size();
            for (int i = 0; i < n / 2; ++i){
                int a = min(nums[i], nums[n - i - 1]);
                int b = max(nums[i], nums[n - i - 1]);
                count_sum[a+b]++;
                arr_c.push_back(a + 1);
                arr_d.push_back(b + limit);
            }

            std::sort(arr_c.begin(), arr_c.end());
            std::sort(arr_d.begin(), arr_d.end());
            int ans = INT_MAX;
            for (int s = 2; s <= 2 * limit; ++s){
                // find 
                auto [pair_1moves, pair_2moves] = count_sweepline(arr_c, arr_d, s);
                pair_1moves -= (count_sum.find(s) == count_sum.end()) ? 0 : count_sum[s];
                int moves = pair_1moves + 2 * pair_2moves;
                cout << "s = " << s << " pair_1moves = " << pair_1moves << " pair_2moves = " << pair_2moves << " moves = " << moves << "\n";
                ans = min(ans, moves);
            }
            return ans;
        }

        // O(n + L)
        int minMovesSweeplineOnArray(vector<int>& nums, int limit){
            unordered_map<int, int> count_sum;
            map<int, int> diff;

            int n = nums.size();
            // example: [1, 2, 4, 3], L = 2
            // p1: [1, 3] => [2, 5]
            // p2: [2, 4] => [3, 6]
            // [2 3 6 7] => [1, 2, 1, 0]
            for (int i = 0; i < n / 2; ++i){
                int a = min(nums[i], nums[n - i - 1]);
                int b = max(nums[i], nums[n - i - 1]);
                count_sum[a+b]++;
                // active room for range [a + 1, b + L]
                diff[a+1]++;
                diff[b+limit+1]--;
            }
            // now, we have interval time point x1 ... x2 ... x3 ... x4 where 
            // number of pairs that rooms/sum change at that point <=> the number of moves changes at that point

            int ans = INT_MAX;
            int pair_1move = 0;
            // for (auto [s, delta] : diff){
            for (int s = 2; s <= 2 * limit; ++s){
                pair_1move += diff[s];
                int pair_2move = n / 2 - pair_1move;
                int actual_pair_1move = pair_1move - count_sum[s];
                int moves = actual_pair_1move + 2 * pair_2move;
                ans = min(ans, moves);
                // cout << "s=" << s << " - delta=" << delta << " -> pair_1move=" << pair_1move << " - pair_2move=" << pair_2move << " - actual_pair_1move=" << actual_pair_1move << "\n";
            }
            return ans;
        }

        int minMoves(vector<int>& nums, int limit) {
            return minMovesSweeplineOnArray(nums, limit);    
        }
};

int main(){
    Solution sol;

    return 0;
}