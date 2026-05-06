#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static const long long MOD = 1000000007;

    static const int MAXN = 2000000;
    vector<long long> fact, invFact;

    long long modPow(long long base, long long exp) {
        long long result = 1 % MOD;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    long long modInverse(long long a) {
        return modPow(a, MOD - 2);
    }

    void buildFactorials(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i+1] * (i+1)) % MOD;
        }
    }

    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return ((fact[n] * invFact[k]) % MOD) * invFact[n - k] % MOD;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        vector<long long> flerdovika(3);
        flerdovika[0] = n;
        flerdovika[1] = m;
        flerdovika[2] = k;

        if (n == 1) {
            return (k == 0 ? m % MOD : 0);
        }

        buildFactorials(n - 1);

        long long chooseVal = nCk(n - 1, k);
        long long ways = chooseVal % MOD;

        ways = (ways * m) % MOD;

        long long expVal = (long long)(n - 1) - k;
        if (expVal < 0) {
            return 0;
        }

        long long powTerm = modPow(m - 1, expVal);
        ways = (ways * powTerm) % MOD;

        return (int)ways;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    int n = 4, m = 2, k = 2;
    Solution sol;
    cout << sol.countGoodArrays(n, m, k);

    return 0;
}