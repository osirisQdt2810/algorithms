#ifndef DSA_STRING_STRING_TYPES_HPP
#define DSA_STRING_STRING_TYPES_HPP

namespace dsa::string {
    
    inline constexpr long long HASH_BASE = 31;
    inline constexpr long long HASH_MOD = 1e9 + 9;

    using HashType = long long;

    /**
     * @brief Determines the exponent direction used in polynomial rolling hash.
     *
     * Forward:  h(s) = s[0]*p^0 + s[1]*p^1 + ... + s[n-1]*p^(n-1)
     * Backward: h(s) = s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]*p^0
     */
    enum class HashPolicy {
        Forward,   // s[i] * p^i
        Backward,  // s[i] * p^(n-1-i)
    };

}  // namespace dsa::string

#endif  // DSA_STRING_STRING_TYPES_HPP
