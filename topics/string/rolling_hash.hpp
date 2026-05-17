#ifndef DSA_STRING_ROLLING_HASH_HPP
#define DSA_STRING_ROLLING_HASH_HPP

#include "arithmetic/algebra.hpp"
#include "string/string_types.hpp"
#include <string>
#include <vector>

namespace dsa::string {

    /**
     * Polynomial rolling hash with compile-time policy selection.
     *
     * @details:
     * Forward:  hash_[k+1] = hash_[k] + s[k] * BASE^k
     *           => hash_[n] = s[0]*BASE^0 + s[1]*BASE^1 + ... + s[n-1]*BASE^(n-1)
     *           substring hash(i,j) requires mod_inv(BASE^i)
     *
     * Backward: hash_[k+1] = hash_[k] * BASE + s[k]   (Horner's method)
     *           => hash_[n] = s[0]*BASE^(n-1) + s[1]*BASE^(n-2) + ... + s[n-1]*BASE^0
     *           => hash_[0] = 0
     *           => hash_[1] = s[0] * BASE^0                                    (not s[0] * BASE^(n-1))
     *           => hash_[2] = s[0] * BASE^1 + s[1] * BASE^0                    (not s[0] * BASE^(n-1) + s[1] * BASE^(n-2))
     *           => hash_[3] = s[0] * BASE^2 + s[1] * BASE^1 + s[2] * BASE^0    (not s[0] * BASE^(n-1) + s[1] * BASE^(n-2) + s[2] * BASE^(n-3))
     *           ............
     *           substring hash(i,j) = hash_[j+1] - hash_[i] * BASE^(j+1-i), no mod_inv needed
     * 
     */
    template<HashPolicy Policy = HashPolicy::Forward>
    class StringHash {
        private:
            const std::string& s_;
            std::vector<HashType> hash_;

        private:
            void init_hash(){
                int n = s_.size();
                hash_.assign(n + 1, 0);

                if constexpr (Policy == HashPolicy::Forward) {
                    HashType pow = 1;
                    for (int k = 0; k < n; ++k) {
                        hash_[k+1] = (hash_[k] + (s_[k] - 'a' + 1) * pow) % HASH_MOD;
                        pow = (pow * HASH_BASE) % HASH_MOD;
                    }
                } else {
                    for (int k = 0; k < n; ++k) {
                        hash_[k+1] = (hash_[k] * HASH_BASE + (s_[k] - 'a' + 1)) % HASH_MOD;
                    }
                }
            }

        public:
            StringHash(){}
            StringHash(const std::string& s) : s_(s) {
                init_hash();
            }

        public:
            /**
             * @brief H[s0...sn-1]
             */
            inline HashType hash() const {
                return hash_[s_.size()];
            }

            /**
             * @brief H[s0...si]
             */
            inline HashType hash(int i) const {
                return hash_[i + 1];
            }

            /**
             * @brief H[si...sj]
             *
             * Forward:  (hash_[j+1] - hash_[i]) * mod_inv(BASE^i)
             * Backward: (hash_[j+1] - hash_[i] * BASE^(j+1-i))
             */
            inline HashType hash(int i, int j) const {
                if constexpr (Policy == HashPolicy::Forward) {
                    HashType val = (hash_[j + 1] - hash_[i] + HASH_MOD) % HASH_MOD;
                    HashType fact = Algebra::mod_power(HASH_BASE, i, HASH_MOD);
                    return val * Algebra::mod_inv(fact, HASH_MOD) % HASH_MOD;
                } else {
                    HashType scale = Algebra::mod_power(HASH_BASE, j + 1 - i, HASH_MOD);
                    return (hash_[j + 1] - hash_[i] * scale % HASH_MOD + HASH_MOD) % HASH_MOD;
                }
            }

            /**
             * @brief Compute full hash of an arbitrary string without building prefix array.
             */
            static inline HashType hash(const std::string& s) {
                HashType h = 0;
                if constexpr (Policy == HashPolicy::Forward){
                    HashType p = 1;
                    for (auto c : s){
                        h = (h + (c - 'a' + 1) * p) % HASH_MOD;
                        p = (p * HASH_BASE) % HASH_MOD;
                    }
                }
                else {
                    for (auto c : s){
                        h = (h * HASH_BASE + (c - 'a' + 1)) % HASH_MOD;
                    }
                }
                return h;
            }
    };

}  // namespace dsa::string

#endif  // DSA_STRING_ROLLING_HASH_HPP
