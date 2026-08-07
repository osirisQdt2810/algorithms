#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
    LC 732 - My Calendar III
    https://leetcode.com/problems/my-calendar-iii/

    Problem:
        A k-booking happens when k events have some non-empty intersection (i.e., there is some
        time that is common to all k events).

        You are given some events [startTime, endTime); after each given event, return an integer
        k representing the maximum k-booking between all the previous events.

        Implement the MyCalendarThree class:
          - MyCalendarThree() Initializes the object.
          - int book(int startTime, int endTime) Returns an integer k representing the largest
            integer such that there exists a k-booking in the calendar.

        Constraints:
          - 0 <= startTime < endTime <= 10^9
          - At most 400 calls will be made to book.

    Examples:
        Example 1:
            Input
                ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
                [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
            Output
                [null, 1, 1, 2, 3, 3, 3]
            Explanation
                MyCalendarThree myCalendarThree = new MyCalendarThree();
                myCalendarThree.book(10, 20); // return 1
                myCalendarThree.book(50, 60); // return 1
                myCalendarThree.book(10, 40); // return 2
                myCalendarThree.book(5, 15);  // return 3
                myCalendarThree.book(5, 10);  // return 3
                myCalendarThree.book(25, 55); // return 3

    Best solution:
        Dynamic (sparse) segment tree over the value range [0, 10^9] with lazy range-add and
        range-max, allocating nodes only along the paths actually touched.

    Complexity:
        Time:  O(n log C) total, O(log C) per book with C = 10^9 — each update walks O(log C)
               levels and splits into O(log C) canonical nodes.
        Space: O(n log C) — at most O(log C) fresh nodes are created per booking, instead of the
               O(C) nodes a dense tree over the full range would need.

    Approach (detail):
        1. Model the answer as a maximum over a "coverage" function: cover[t] = how many booked
           events contain time t. Booking [startTime, endTime) means cover[t] += 1 for every t in
           [startTime, endTime-1], and the answer after each call is max over all t of cover[t].
           So the problem is exactly "range add 1, query global max".
        2. A segment tree supports that pair of operations in logarithmic time, but the time axis
           spans 10^9 points, far too many to allocate up front. Build the tree lazily instead:
           the root covers [0, 10^9] and a child node is materialised with `new node()` only when
           an update or a push_down first needs to descend into it. Untouched subtrees stay null
           and are read as coverage 0.
        3. Each node stores val (the maximum coverage inside its range) and lazy (a pending
           increment that has been applied to val but not yet propagated to its children).
        4. update(curr, l, r, X, Y): if [l,r] is disjoint from [X,Y] return unchanged; if [l,r] is
           fully inside [X,Y], bump both val and lazy by 1 and stop — the whole segment shifts up
           uniformly, so its maximum shifts up by exactly 1 and the children can be told later.
           Otherwise push_down the pending lazy into both children (creating them if needed),
           recurse on both halves, and recompute val = max(left->val, right->val).
        5. Because a range add shifts every element of a segment by the same amount, the maximum
           of that segment shifts by the same amount too. That is what makes the lazy tag valid
           for a max tree and keeps each update to O(log C) visited nodes.
        6. The answer to each book call is simply the root's val after the update, i.e. the global
           maximum coverage — no separate query is required.
        7. Half-open handling: the event covers [startTime, endTime), so the tree is updated over
           the inclusive integer range [startTime, endTime-1]. Without this, two events that merely
           touch at a shared endpoint would be counted as overlapping.

        Alternative (accepted here because n <= 400): keep a difference map<int,int> with
        diff[startTime]++ and diff[endTime]--, then sweep the map in key order accumulating a
        running counter and tracking its maximum. That is O(n) per call and O(n^2) overall, which
        is fine for 400 calls but strictly worse than the segment tree asymptotically.

    Your solution:
        SUBOPTIMAL — the live book() is the difference-map sweep, not the segment tree. It walks
        the whole map on every call, so it runs in O(n) per booking and O(n^2) overall with O(n)
        space, against O(log C) per booking and O(n log C) for the optimal dynamic lazy segment
        tree. It still passes comfortably because the constraints cap book at 400 calls (~160k
        map steps worst case), so the quadratic term never bites here — but it would not scale.
        The optimal implementation is present and correct in this file as book2(), which drives
        lazy_dynamic_segtree over [0, 1e9] and updates the inclusive range [startTime, endTime-1];
        it is currently dead code, since LeetCode only calls book(). Swapping the two method
        bodies is all that is needed to make this file optimal.
*/

class MyCalendarThree {
    private:
        struct node {
            int val{0};
            int lazy{0};
            node* lc{nullptr};
            node* rc{nullptr};
        };

        struct lazy_dynamic_segtree {
            int n;
            node* root;

            lazy_dynamic_segtree() : n(1e9), root(new node()){}

            void push_down(node* curr, int l, int r){
                if (curr->lazy == 0) return;
                if (!curr->lc) curr->lc = new node();
                if (!curr->rc) curr->rc = new node();

                int m = (l+r)/2;
                curr->lc->val += curr->lazy;
                curr->rc->val += curr->lazy;

                curr->lc->lazy += curr->lazy;
                curr->rc->lazy += curr->lazy;
                curr->lazy = 0;
            }

            node* update(node* curr, int l, int r, int X, int Y){
                // case 1: [l...r] [X...Y] or [X...Y][l...r]
                if (r < X || Y < l) return curr;
                // case 2: [X...l...r...Y]
                if (curr == nullptr) curr = new node();
                if (X <= l && r <= Y){
                    ++curr->val;
                    ++curr->lazy;
                    return curr;
                }
                // case 3: overlap
                push_down(curr, l, r);
                int m = (l+r)/2;
                curr->lc = update(curr->lc, l, m, X, Y);
                curr->rc = update(curr->rc, m+1, r, X, Y);
                if (curr->lc) curr->val = max(curr->val, curr->lc->val);
                if (curr->rc) curr->val = max(curr->val, curr->rc->val);
                return curr;
            }

            int query(node* curr, int l, int r, int X, int Y){
                // case 1: [l...r] [X...Y] or [X...Y][l...r]
                if (r < X || Y < l || curr == nullptr) return 0;
                // case 2: [X...l...r...Y]
                if (X <= l && r <= Y) return curr->val;
                // case 3: overlap
                int m = (l+r)/2;
                push_down(curr, l, r);
                return max(query(curr->lc, l, m, X, Y), query(curr->rc, m+1, r, X, Y));
            }

            int query(int X, int Y){
                return query(root, 0, n, X, Y);
            }
            
            int update(int X, int Y){
                return update(root, 0, n, X, Y)->val;
            }
        };

        lazy_dynamic_segtree tree;
        map<int, int> diff;

    public:
        MyCalendarThree() {

        }
        
        int book2(int startTime, int endTime) {
            return tree.update(startTime, endTime-1);
        }

        int book(int startTime, int endTime) {
            diff[startTime]++;
            diff[endTime]--;

            int counter = 0;
            int res = 0;
            for (auto& [time, d] : diff){
                counter += d;
                res = max(res, counter);
            }
            return res;
        }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();