#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void digits(vector<int>& dgs, int i){
            if (i == 0) return;
            digits(dgs, i / 10);
            dgs.push_back(i % 10);
        }

        int buildNumber(vector<int>& dgs, int l, int r){
            int sum = 0, pow = 1;
            for (int i = r; i >= l; --i){
                sum += dgs[i] * pow;
                pow *= 10;
            }
            
            return sum;
        }

        bool recursive(vector<int>& digits, int sum, int l, int N){
            if (l == N || sum < 0) return false;
            if (sum == buildNumber(digits, l, N - 1)) return true;

            for (int i = l + 1; i < N; ++i){
                if (recursive(digits, sum - buildNumber(digits, l, i - 1), i, N))
                    return true;
            }

            return false;
        }

        bool isValidInteger(int i){
            vector<int> dgs;
            digits(dgs, i * i);
            return recursive(dgs, i, 0, dgs.size());
        }

    public:
        int punishmentNumber(int n) {
            int res = 0;
            for (int i = 1; i <= n; ++i)
                res += isValidInteger(i) ? i * i : 0;
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
    int n = 10;
    cout << sol.punishmentNumber(n) << endl;
    return 0;
}