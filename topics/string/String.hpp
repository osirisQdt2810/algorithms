#pragma once

#include "arithmetic/Arithmetic.hpp"
#include <bits/stdc++.h>

using namespace std;

struct StringDef {
    static const int P = 31;
    static const int M = 1e9 + 9;
};

class StringHash : public StringDef {
    private:
        std::string input;
        vector<long long> h;

    public:
        StringHash(){}
        StringHash(const string& s) : input(s){
            int n = input.size();
            long long p_pow = 1;
            
            h.assign(n + 1, 0);
            for (int k = 0; k < n; ++k){
                h[k+1] = (h[k] + (s[k] - 'a' + 1) * p_pow) % M;
                p_pow = (p_pow * P) % M;
            }
        }

    public:
        /**
         * @brief H[s] = sigma(s[i] * p^i) % M
         */    
        inline long long hash(){
            return h[input.size()];
        }

        /**
         * @brief H[si...sj] = sigma[k=i->j](s[k] * p ^ (k-i)) % M
         *   <=>  H[si...sj] * p^i = sigma[k=1->j](s[k] * p^k]) % M = (H[s_j] - H[s_i-1]) % M
         */
        inline long long hash(int i, int j){
            long long hash = (h[j + 1] + M - h[j]) % M;
            long long fact = Arithmetic::mod_power(P, i, M);
            return hash * Arithmetic::mod_inv(fact, M) % M;
        }

        /**
         * @brief H[s0...si]
         */
        inline long long hash(int i){
            return h[i+1];
        }

        /**
         * @brief H[s] = sigma(s[i] * p^i) % M
         */
        static inline long long hash(const string& s){
            long long hash = 0;
            long long p_pow = 1;
            for (char c : s){
                hash = (hash + (c - 'a' + 1) * p_pow) % M;
                p_pow = (P * p_pow) % M;
            }
            return hash;
        }
};

class StringMatching : public StringDef {
    public:
        static inline vector<int> z_algo(const string &s) {
            int n(s.size());
            vector<int> z(n);

            int l(0), r(0);
            for (int i=1; i<n; i++) {
                if (i > r) {
                    l = r = i;
                    while (r<n && s[r-l]==s[r]) r += 1;
                    z[i] = r - l;
                    r -= 1;
                } else if (z[i-l] < r-i+1) {
                    z[i] = z[i-l];
                } else {
                    l = i;
                    while (r<n && s[r-l]==s[r]) r += 1;
                    z[i] = r - l;
                    r -= 1;
                }
            }
            return z;
        }

        static inline vector<int> z_matching(const string& s, const string& pattern){
            static const char DELIMITER = '.';
            string T = pattern + DELIMITER + s;
            auto z_res = z_algo(T);
            vector<int> res;
            for (int i = 0; i < z_res.size(); ++i){
                if (z_res[i] == static_cast<int>(pattern.length()))
                    res.push_back(i - pattern.length() - 1);
            }
            return res;
        }

        static inline vector<int> rabin_karp(
            const string& s, const string& pattern, 
            bool assurance = false
        ){
            int pSize = pattern.size(), sSize = s.size();
            vector<int> occurences;

            long long hp = StringHash::hash(pattern);
            auto hasher = StringHash(s);
            long long pow_i = 1;
            
            for (int i = 0; i < sSize - pSize + 1; ++i){
                int j = i + pSize - 1;
                long long hij = hasher.hash(j) - hasher.hash(i - 1);
                if (hij == pow_i * hp){
                    if (!assurance || !pattern.compare(s.substr(i, pSize)))
                        occurences.push_back(i);
                }
                
                pow_i *= P;
            }

            return occurences;
        }
};