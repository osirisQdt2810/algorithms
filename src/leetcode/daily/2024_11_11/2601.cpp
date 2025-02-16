#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Arith {
    public:
        static inline vector<int> eratos(int N){
            int UPPER_BOUND = 1e3 + 1;
            vector<bool> mask(UPPER_BOUND, true);
            mask[0] = true;
            mask[1] = false; 

            for (int l = 2; l <= sqrt(UPPER_BOUND); ++l){
                if (mask[l]){
                    for (int j = l * l; j <= UPPER_BOUND; j += l){
                        mask[j] = false;
                    }
                }
            }

            vector<int> primes;
            for (int i = 0; i <= N; ++i){
                if (mask[i]){
                    primes.push_back(i);
                }
            }
            return primes;
        }  
};

class Solution {
    public:
        // bool primeSubOperationLowVersion(vector<int>& nums) {
        //     // convert to sub-problem
        //     int maxNum = *max_element(nums.begin(), nums.end());
        //     vector<int> primes = Arith::eratos(maxNum);
        //     vector<vector<int>> subNum; subNum.resize(nums.size());

        //     for (size_t i = 0; i < nums.size(); ++i){
        //         for (int p : primes){
        //             if (p >= nums[i]) break;
        //             if (nums[i] - p <= i) continue;
        //             subNum[i].push_back(nums[i] - p);
        //         }
        //     }

        //     int curr = 1e7;
        //     for (int k = nums.size() - 1; k >= 0; --k){
        //         auto& lst = subNum[k];
        //         bool retr = true;
        //         for (size_t i = 0; i < lst.size(); ++i){
        //             if (curr <= lst[i]) continue;
        //             curr = lst[i];
        //             retr = false;
        //             break;
        //         }

        //         if (retr) return false;
        //     }
        //     return true;
        // }

    private:
        int binarySearch(const vector<int>& nums, int Q){
            int l = 0, r = nums.size() - 1, ans = -1;
            // cout << "l = " << l << " r = " << r << " \n";
            while (l <= r){
                int mid = (l + r) / 2;
                if (nums[mid] < Q){
                    ans = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            return ans;
        }
    public:
        bool primeSubOperation(vector<int>& nums) {
            // convert to sub-problem
            // int maxNum = *max_element(nums.begin(), nums.end());
            // vector<int> primes = Arith::eratos(1001);
            vector<int> primes = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021};
            vector<vector<int>> subNum; subNum.resize(nums.size());

            for (size_t i = 0; i < nums.size(); ++i){       // use two loops make beats only 7% => we dont need to do this, just put `primes` right in the binary_search
                for (int p : primes){
                    // cout << "i = " << i << " : nums[i] = " << nums[i] << " p = " << p << "\n";
                    if (p >= nums[i]) break;
                    if (nums[i] - p <= i) continue;
                    subNum[i].push_back(nums[i] - p);
                }
            }

            // for (size_t i = 0; i < nums.size(); ++i){
                // cout << "i = " << i << " nums[i] = " << nums[i] << ": ";
            //     for (auto t : subNum[i]){
                    // cout << " " << t << " ";
            //     }
                // cout << "\n";
            // }

            // cout << "algo\n";
            int N = nums.size() - 1;
            if (subNum[N].empty()){
                return false;
            }
            int currMaxValue = subNum[N][0];

            for (int k = N - 1; k >= 0; --k){
                if (subNum[k].empty()) return false;
                if (currMaxValue > subNum[k][0]) {
                    currMaxValue = subNum[k][0];
                    continue;
                }

                int targetIdx = binarySearch(subNum[k], currMaxValue);
                if (targetIdx < 0){
                    return false;
                }
                // cout << "targetIdx = " << targetIdx << "\n";
                currMaxValue = subNum[k][targetIdx];
            }

            return true;
        }        
};

int main(){
    vector<int> nums {11, 2, 10, 15, 19};
    Solution s;
    cout << (s.primeSubOperation(nums) ? "true": "false");
}