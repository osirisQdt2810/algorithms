#ifndef DSA_LINEAR_MONOTONIC_STACK_HPP
#define DSA_LINEAR_MONOTONIC_STACK_HPP

#include "utility.hpp"

#include <stack>

namespace dsa::linear::stack {

    /**
     * MonotonicStack — O(1) amortized Previous Smaller/Greater Element.
     *
     * Maintains a stack whose elements are monotone from bottom to top.
     * On each push(v), pops all elements that violate the invariant with v;
     * those popped elements are dominated by v and can never be the answer.
     * Returns the element just below v after popping = Previous Smaller/Greater Element.
     *
     * Invariant: cmpr(st[i], st[i+1]) == true for all i (bottom to top).
     *   less<T>    → increasing stack → push() returns Previous Smaller Element (PSE)
     *   greater<T> → decreasing stack → push() returns Previous Greater Element (PGE)
     *
     * Example — IncreasingMonotonicStack, array=[2,1,3,0]:
     *   push(2): stack=[]      → res=identity → stack=[2]
     *   push(1): 2>=1, pop 2   → res=identity → stack=[1]
     *   push(3): 1>=3? No      → res=1        → stack=[1,3]   ← PSE of 3 is 1 ✓
     *   push(0): 3>=0, 1>=0, pop both → res=identity → stack=[0]
     *
     * @tparam T         Element type.
     * @tparam identity  Sentinel returned when no previous smaller/greater element exists.
     * @tparam Compare   Use less<T> for increasing stack (PSE), greater<T> for decreasing (PGE).
     */
    template<typename T, class Compare = dsa::utility::cmpr::less<T>>
    class MonotonicStack {
        private:
            std::stack<T> st;
            Compare cmpr;
            T identity;

        public:
            MonotonicStack(T identity_) : identity(identity_){}

            T push(const T& value) {
                while (!st.empty() && !cmpr(st.top(), value)) st.pop();
                T res = (st.empty()) ? identity : st.top();
                st.push(value);
                return res;
            }

            T pop() { 
                T res = st.top(); st.pop(); 
                return res; 
            }
            
            T top() const { return st.top(); }
            bool empty() const { return st.empty(); }
            int  size()  const { return static_cast<int>(st.size()); }
    };

    template<typename T, typename IndexType, class Compare = dsa::utility::cmpr::less<T>>
    class IndexMonotonicStack {
        private:
            std::stack<IndexType> st;
            const std::vector<T>& nums;
            IndexType identity;

            Compare cmpr;

        public:
            IndexMonotonicStack(const std::vector<T>& nums_, IndexType identity_) : nums(nums_), identity(identity_){}

            IndexType push(IndexType i) {
                while (!st.empty() && !cmpr(nums[st.top()], nums[i])) st.pop();
                IndexType res = (st.empty()) ? identity : st.top();
                st.push(i);
                return res;
            }

            IndexType pop() { 
                IndexType res = st.top(); st.pop(); 
                return res; 
            }
            
            IndexType top() const { return st.top(); }
            bool empty() const { return st.empty(); }
            int  size()  const { return static_cast<int>(st.size()); }
    };

    template<typename T>
    using IncreasingMonotonicStack = MonotonicStack<T, dsa::utility::cmpr::less<T>>;

    template<typename T>
    using DecreasingMonotonicStack = MonotonicStack<T, dsa::utility::cmpr::greater<T>>;

    template<typename T>
    using IncreasingIndexMonotonicStack = IndexMonotonicStack<T, int, dsa::utility::cmpr::less<T>>;

    template<typename T>
    using DecreasingIndexMonotonicStack = IndexMonotonicStack<T, int, dsa::utility::cmpr::greater<T>>;

} // namespace dsa::linear::stack

#endif // DSA_LINEAR_MONOTONIC_STACK_HPP
