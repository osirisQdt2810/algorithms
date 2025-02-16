#pragma once

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Arithmetic {
    private:
        static const ll UPPER_BOUND = 1e7;

    public:
        static inline vector<ll> eratos(ll N){
            vector<bool> mask(UPPER_BOUND, true);
            mask[0] = mask[1] = false; 

            for (ll l = 2; l <= sqrt(UPPER_BOUND); ++l){
                if (mask[l]){
                    for (ll j = l * l; j <= UPPER_BOUND; j += l){
                        mask[j] = false;
                    }
                }
            }

            vector<ll> primes;
            for (ll i = 0; i <= N; ++i){
                if (mask[i]){
                    primes.push_back(i);
                }
            }
            return primes;
        }

        /**
         * @brief a^n % mod 
         */
        static inline long long mod_power(long long a, long long n, const long long& mod = 1e9 + 7){
            if (n == 0) return 1;
            if (n == 1) return a % mod;
            long long t = mod_power(a, n / 2, mod);
            t = t * t % mod;
            return t * mod_power(a, n % 2, mod) % mod;
        }

        /**
         * @brief a^-1 % p (inverse power, (a, p) = 1)
         */
        static inline long long mod_inv(long long a, long long p){
            return mod_power(a % p, p-2, p);
        }

        /**
         * @brief n! % mod 
         */
        static inline long long mod_factorial(long long n, const long long& mod = 1e9 + 7){
            long long f = 1;
            for (int i = 1; i <= n; ++i)
                f = f * i % mod;
            return f;
        }

        /**
         * @brief Ck_n % mod where mod = p
         */
        static inline long long mod_combination(long long n, long long k, const long long& mod = 1e9 + 7){
            vector<long long> fact(n + 1);
            fact[0] = 1;
            for (int i = 1; i <= n; ++i)
                fact[i] = fact[i - 1] * i % mod;
            
            long long t = mod_power(fact[k] * fact[n - k] % mod, mod - 2, mod);
            return fact[n] * t % mod;
        }
};