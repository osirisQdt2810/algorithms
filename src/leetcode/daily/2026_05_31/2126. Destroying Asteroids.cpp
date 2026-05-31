#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
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

    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long ll_mass = mass;
        for (int a : asteroids) {
            if (a > ll_mass) return false;
            ll_mass += a;
        }
        return true;
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