#include <bits/stdc++.h>

using namespace std;

/**
 *  1652. Defuse the Bomb
        You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

        To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

        If k > 0, replace the ith number with the sum of the next k numbers.
        If k < 0, replace the ith number with the sum of the previous k numbers.
        If k == 0, replace the ith number with 0.
        As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

        Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
 */
class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            vector<int> res(code.size(), 0);
            int N = code.size();

            if (k == 0){
                return res;
            }

            vector<int> sum(N, 0); sum[0] = code[0];
            for (int i = 1; i < N; ++i){
                sum[i] = sum[i-1] + code[i];
            }

            if (k > 0){
                for (int i = 0; i < N; ++i){
                    if (i + k >= N){
                        res[i] = (sum[N - 1]  - sum[i]) + ((i + k - N + 1) / N * sum[N - 1]) + sum[(i + k) % N];
                    }
                    else {
                        res[i] = sum[i + k] - sum[i];
                    }
                }
            }

            if (k < 0){
                k = -k;
                for (int i = 0; i < N; ++i){
                    if (i - k >= 0){
                        res[i] = sum[i - 1] - ((i - k - 1 >= 0) ? sum[i - k - 1] : 0);
                    }
                    else {
                        if ((k - i) % N  == 0){
                            res[i] = ((i >= 1) ? sum[i - 1] : 0) + ((k - i) / N * sum[N - 1]);
                        }
                        else {
                            res[i] = ((i >= 1) ? sum[i - 1] : 0) + ((k - i) / N * sum[N - 1]) + (sum[N - 1] - sum[N - 1 + (i - k) % N]);
                        }
                    }
                }
            }

            return res;
        }
};

int main(){
    vector<int> code = {5,7,1,4}; int k = -2;

    cout << (-2) % 4 << "\n";

    Solution s;
    for (auto e : s.decrypt(code, k)){
        cout << e << " ";
    }
    return 0;
}