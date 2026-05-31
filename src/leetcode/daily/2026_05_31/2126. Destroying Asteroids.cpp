#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    // O(nlogn) time, O(n) space
    bool asteroidsDestroyedPQ(int mass, vector<int>& asteroids) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& a: asteroids) pq.push(a);

        long long ll_mass = mass;
        while (!pq.empty()){
            int a = pq.top(); pq.pop();
            if (a > ll_mass) return false;
            ll_mass += a;
        }
        return true;
    }

    // O(nlogn) time, O(1) space
    bool asteroidsDestroyedSort(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long ll_mass = mass;
        for (int a : asteroids) {
            if (a > ll_mass) return false;
            ll_mass += a;
        }
        return true;
    }

    // O(n) time, O(n) space
    bool asteroidsDestroyedBucket(int mass, vector<int>& asteroids) {
        // 1 ý tưởng rất hay => bucket-based approach => bucket như nào nếu ta không biết được max của asteroids?
        // => ta bucket theo range của bit, chứ không bucket theo khoảng có giá trị bằng nhau
        // => bucket[k] chứa phần tử thuộc [2^k, 2^(k+1)), gọi min[k] là phần tử min của bucket[k]
        // => ta sẽ duyệt bucket từ nhỏ đến lớn, nếu tại k:
        //        - min[k] > mass => return false
        //        - min[k] <= mass => mass + min >= 2^k + 2^k > max(bucket[k]) => ta có thể ăn hết bucket[k] => mass += sum(bucket[k])
        // => ta sẽ có O(n) time, O(n) space

        using ll = long long;
        constexpr int RANGE = 32;
        vector<ll> sum_bucket(RANGE, 0);
        vector<int> min_bucket(RANGE, INT_MAX);

        for (auto& a : asteroids){
            // int k = floor(log2(a));
            // similar approach:
            int k = RANGE - 1 - __builtin_clz(a); // clz: Count Leading Zeros => số lượng 0 liên tiếp nằm ở vị trí đầu tiên
            sum_bucket[k] += a;
            min_bucket[k] = min(min_bucket[k], a);
        }
        long long ll_mass = mass;
        for (int k = 0; k < RANGE; ++k){
            if (min_bucket[k] == INT_MAX) continue;
            if (ll_mass < min_bucket[k]) return false;
            ll_mass += sum_bucket[k];
        }
        return true;
    }

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        return asteroidsDestroyedBucket(mass, asteroids);
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;

    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};
    bool result = sol.asteroidsDestroyed(mass, asteroids);
    cout << result << endl;
    return 0;
}