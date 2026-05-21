#ifndef DSA_UTILITY_HPP
#define DSA_UTILITY_HPP

#include <type_traits>
#include <limits>

namespace dsa::utility {
    namespace monoid {
        template<typename ValueType>
        struct sumops {
            static constexpr ValueType identity(){ return ValueType(0); }
            static ValueType combine(const ValueType& a, const ValueType& b){ return a + b; }
        };

        template<typename ValueType>
        struct maxops {
            static constexpr bool is_comparative = true;
            static constexpr ValueType identity(){ return std::numeric_limits<ValueType>::lowest(); }
            static ValueType combine(const ValueType& a, const ValueType& b){ return (a > b) ? a : b; }
        };

        template<typename ValueType>
        struct minops {
            static constexpr bool is_comparative = true;
            static constexpr ValueType identity(){ return std::numeric_limits<ValueType>::max(); }
            static ValueType combine(const ValueType& a, const ValueType& b){ return (a < b) ? a : b; }
        };

        template<typename ValueType>
        struct gcdops {
            static constexpr ValueType identity(){ return ValueType(0); }
            static ValueType combine(const ValueType& a, const ValueType& b){ return std::__algo_gcd(a, b); }
        };

        template<typename ValueType>
        struct lcmops {
            static constexpr ValueType identity(){ return ValueType(1); }
            static ValueType combine(const ValueType& a, const ValueType& b){ return 0; }   // @todo: add lcm for lcmops 
        };

        template<typename O, typename W, typename = void>
        struct is_valid_monoid_ops : std::false_type {};

        template<typename O, typename W>
        struct is_valid_monoid_ops<O, W, std::void_t<
            decltype(O::identity()),
            decltype(O::combine(std::declval<W>(), std::declval<W>()))
        >> : std::bool_constant<
            std::is_convertible_v<decltype(O::identity()), W> &&
            std::is_convertible_v<
                decltype(O::combine(std::declval<W>(), std::declval<W>())), W
            >
        > {};

        template<typename O, typename W, typename = void>
        struct is_valid_monoid_comparative_ops : std::false_type {};

        template<typename O, typename W>
        struct is_valid_monoid_comparative_ops<O, W,
            std::enable_if_t<O::is_comparative && is_valid_monoid_ops<O, W>::value>
        > : std::true_type {};
    }

    namespace cmpr {
        template<typename T>
        struct less {
            inline bool operator()(const T& a, const T& b) const { return a < b; }
        };

        template<typename T>
        struct greater {
            inline bool operator()(const T& a, const T& b) const { return a > b; }
        };

        template<typename T>
        struct equal {
            inline bool operator()(const T& a, const T& b) const { return a == b; }
        };

        template<typename T>
        struct less_equal {
            inline bool operator()(const T& a, const T& b) const { return a <= b; }
        };

        template<typename T>
        struct greater_equal {
            inline bool operator()(const T& a, const T& b) const { return a >= b; }
        };

        template<typename T>
        struct not_equal {
            inline bool operator()(const T& a, const T& b) const { return a != b; }
        };
    } // namespace dsa::utility

#endif // DSA_UTILITY_HPP
