#ifndef DSA_LINEAR_MONOTONIC_QUEUE_HPP
#define DSA_LINEAR_MONOTONIC_QUEUE_HPP

#include "utility.hpp"

#include <deque>

namespace dsa::linear::queue {

    /**
     * MonotonicQueue — O(1) amortized sliding window min/max.
     *
     * Two internal deques:
     *   candidate_queue : all elements in the window (insertion order), used to
     *                     detect which element leaves on dequeue().
     *   info_queue      : monotone deque of "candidate" elements; front = answer.
     *
     * Invariant: cmpr(info[i], info[i+1]) == true for all i.
     *   greater_equal → non-increasing  → front is window MAXIMUM
     *   less_equal    → non-decreasing  → front is window MINIMUM
     *
     * enqueue(v): pop back of info_queue while !cmpr(back, v) — those elements
     *   are older and dominated by v, so they can never be the answer.
     *   Non-strict comparators (>=, <=) preserve duplicates so dequeue()'s
     *   value-equality check remains correct when equal values appear in the window.
     *
     * Example — MaximumMonotonicQueue, window=3, array=[1,3,-1,-3,5]:
     *   enqueue(1):  cand=[1],       info=[1]
     *   enqueue(3):  cand=[1,3],     info=[3]       (1 < 3, popped)
     *   enqueue(-1): cand=[1,3,-1],  info=[3,-1]    → query()=3  ✓
     *   dequeue():   cand=[3,-1],    info=[3,-1]     (1≠3, info kept)
     *   enqueue(-3): cand=[3,-1,-3], info=[3,-1,-3] → query()=3  ✓
     *   dequeue():   cand=[-1,-3],   info=[-1,-3]    (3==3, info popped)
     *   enqueue(5):  cand=[-1,-3,5], info=[5]        (-3,-1 < 5, popped) → query()=5 ✓
     *
     * Complexity: O(n) total, O(k) space where k = window size.
     *
     * @tparam T        Element type.
     * @tparam Compare  Use greater_equal<T> for maximum, less_equal<T> for minimum.
     */
    template<typename T, class Compare = dsa::utility::cmpr::less_equal<T>>
    class MonotonicQueue {
        private:
            std::deque<T> candidate_queue;
            std::deque<T> info_queue;
            Compare cmpr;

        public:
            void enqueue(const T& value) {
                while (!info_queue.empty() && !cmpr(info_queue.back(), value)) info_queue.pop_back();
                info_queue.push_back(value);
                candidate_queue.push_back(value);
            }

            void dequeue() {
                if (candidate_queue.empty()) return;
                if (info_queue.front() == candidate_queue.front()) info_queue.pop_front();
                candidate_queue.pop_front();
            }

            T query() const { return info_queue.front(); }
            T front() const { return candidate_queue.front(); }
            T back()  const { return candidate_queue.back(); }

            bool empty() const { return candidate_queue.empty(); }
            int  size()  const { return static_cast<int>(candidate_queue.size()); }
    };

    template<typename T>
    using MaximumMonotonicQueue = MonotonicQueue<T, dsa::utility::cmpr::greater_equal<T>>;

    template<typename T>
    using MinimumMonotonicQueue = MonotonicQueue<T, dsa::utility::cmpr::less_equal<T>>;

} // namespace dsa::linear::queue

#endif // DSA_LINEAR_MONOTONIC_QUEUE_HPP