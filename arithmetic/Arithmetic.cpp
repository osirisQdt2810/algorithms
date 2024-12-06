#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Arith {
    public:
        vector<ll> eratos(ll N){
            ll UPPER_BOUND = 1e7;
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
};
