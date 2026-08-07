#include <unordered_map>
#include <set>
#include <vector>
#include <map>

using namespace std;

/*
    LC 729 - My Calendar I
    https://leetcode.com/problems/my-calendar-i/

    Problem:
        You are implementing a program to use as your calendar. We can add a new event if adding
        the event will not cause a double booking.

        A double booking happens when two events have some non-empty intersection (i.e., some
        moment is common to both events).

        The event can be represented as a pair of integers startTime and endTime that represents a
        booking on the half-open interval [startTime, endTime), the range of real numbers x such
        that startTime <= x < endTime.

        Implement the MyCalendar class:
          - MyCalendar() Initializes the calendar object.
          - boolean book(int startTime, int endTime) Returns true if the event can be added to the
            calendar successfully without causing a double booking. Otherwise, return false and do
            not add the event to the calendar.

        Constraints:
          - 0 <= start < end <= 10^9
          - At most 1000 calls will be made to book.

    Examples:
        Example 1:
            Input
                ["MyCalendar", "book", "book", "book"]
                [[], [10, 20], [15, 25], [20, 30]]
            Output
                [null, true, false, true]
            Explanation
                MyCalendar myCalendar = new MyCalendar();
                myCalendar.book(10, 20); // return True
                myCalendar.book(15, 25); // return False, It can not be booked because time 15 is
                                         // already booked by another event.
                myCalendar.book(20, 30); // return True, The event can be booked, as the first
                                         // event takes every time less than 20, but not
                                         // including 20.

    Best solution:
        Ordered map (balanced BST) of disjoint intervals + predecessor lookup.

    Complexity:
        Time:  O(n log n) total, O(log n) per book — one lower_bound plus one insertion in a
               red-black tree holding at most n intervals.
        Space: O(n) — one map entry per accepted booking.

    Approach (detail):
        1. Keep the accepted events in a map<int,int> keyed by startTime with value endTime.
           Invariant: because every accepted event is checked against the others before insertion,
           the stored intervals are pairwise disjoint and therefore sorted by start AND by end
           simultaneously.
        2. To test a candidate [startTime, endTime), call lower_bound(endTime): it returns the
           first stored interval whose start is >= endTime. Every interval from there onward
           starts at or after endTime, so none of them can intersect the half-open candidate.
        3. The only remaining suspect is the interval immediately before that position — the one
           with the largest start strictly less than endTime. Step back with --it (guarding
           it != begin(), which means nothing starts before endTime and the candidate is free).
        4. That predecessor (s, e) satisfies s < endTime by construction, so the two intervals
           intersect exactly when e > startTime. If so, reject with false.
        5. Why one predecessor suffices: the stored intervals are disjoint and ordered, so their
           end values increase along with their starts. If the predecessor already ends at or
           before startTime, every earlier interval ends even sooner and cannot reach the
           candidate. A single comparison therefore settles the whole calendar.
        6. Otherwise insert calendar[startTime] = endTime and return true, restoring the
           disjointness invariant for the next query.

    Your solution:
        MATCHES BEST — book() is exactly the documented algorithm: one lower_bound(endTime), a
        single step back to the predecessor, and the it->second > startTime overlap test, at
        O(log n) per call with O(n) space. The it != calendar.begin() guard correctly treats "no
        interval starts before endTime" as free, and comparing only the one predecessor is
        sufficient rather than a shortcut, since the stored intervals are kept disjoint.
*/

class MyCalendar {
    private:
        map<int, int> calendar;

    public:
        MyCalendar() {
            
        }
        
        bool book(int startTime, int endTime) {
            auto it = calendar.lower_bound(endTime);
            if (it != calendar.begin()){
                --it;
                if (it->second > startTime) return false;
            }
            calendar[startTime] = endTime;
            return true;
        }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */