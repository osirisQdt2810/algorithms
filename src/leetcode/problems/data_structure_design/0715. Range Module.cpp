#include <unordered_map>
#include <set>
#include <vector>
#include <map>

using namespace std;

using ii = pair<int, int>;
class RangeModule {
private:
    unordered_map<int, int> intervals;
    set<int> lefts;

    map<int, int> invals;

public:
    RangeModule() {}

    void addRange2(int left, int right) {
        int l = left, r = right - 1;

        // merge tất cả intervals bên phải bị overlap
        auto it = lefts.lower_bound(l);
        while (it != lefts.end() && *it <= r + 1) {
            int X = *it;
            r = max(r, intervals[X]);
            intervals.erase(X);
            it = lefts.erase(it);
        }

        // xử lý interval bên trái
        it = lefts.lower_bound(l);
        if (it != lefts.begin()) {
            auto it_l = prev(it);
            int X = *it_l;
            int Y = intervals[X];
            if (Y >= l - 1) {
                l = X;
                r = max(r, Y);
                intervals.erase(X);
                lefts.erase(it_l);
            }
        }

        intervals[l] = r;
        lefts.insert(l);
    }

    bool queryRange2(int left, int right) {
        int l = left, r = right - 1;
        auto it = lefts.upper_bound(l);
        if (it != lefts.begin()) {
            --it;
            int X = *it;
            return X <= l && intervals[X] >= r;
        }
        return false;
    }

    void removeRange2(int left, int right) {
        int l = left, r = right - 1;

        // xử lý interval bên phải: loop để xóa tất cả intervals bị overlap
        auto it = lefts.lower_bound(l);
        while (it != lefts.end() && *it <= r) {
            int X = *it;
            int Y = intervals[X];
            intervals.erase(X);
            it = lefts.erase(it);
            if (Y > r) {
                intervals[r + 1] = Y;
                lefts.insert(r + 1);
                break;
            }
        }

        // xử lý interval bên trái
        it = lefts.lower_bound(l);
        if (it != lefts.begin()) {
            auto it_l = prev(it);
            int X = *it_l;
            int Y = intervals[X];
            if (Y >= l) {
                intervals[X] = l - 1;
                if (Y > r) {
                    intervals[r + 1] = Y;
                    lefts.insert(r + 1);
                }
            }
        }
    }

    void addRange(int left, int right) {
        int l = left, r = right - 1;
        // i....j...k'......k
        // ...l........r
        auto itl = invals.lower_bound(l);
        auto itr = invals.upper_bound(r+1);
        if (itl != invals.begin()){
            --itl;
            if (itl->second < l-1) ++itl;
        }
        int new_l = min(l, (itl == invals.end() ? INT_MAX : itl->first));
        int new_r = max(r, (itr == invals.begin() ? INT_MIN : prev(itr)->second));
        invals.erase(itl, itr);
        invals[new_l] = new_r;
    }

    void removeRange(int left, int right) {
        int l = left, r = right - 1;
        // i....j...k'...Y..k
        // ...l........r
        int last_right = (intervals.empty()) ? INT_MAX : (invals.rbegin()->second);
        if (left > last_right) return;

        auto itl = invals.lower_bound(l);
        auto itr = invals.upper_bound(r);
        
        ii p1 = (itl != invals.begin()) ? ii(*prev(itl)) : ii(-1, INT_MIN);
        ii p2 = (itr != invals.begin()) ? ii(*prev(itr)) : ii(-1, INT_MIN);
        auto [l1, r1] = p1;
        auto [l2, r2] = p2;
        invals.erase(itl, itr);
        if (r1 >= l) invals[l1] = l-1;
        if (r2 > r) invals[r+1] = r2;
    }

    bool queryRange(int left, int right) {
        int l = left, r = right - 1;
        // i....j...k'......k
        // ...l........r
        auto it = invals.lower_bound(l);
        if (it != invals.begin()){
            if ((--it)->second < l) ++it;
        }
        return (it->first <= l && r <= it->second);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */