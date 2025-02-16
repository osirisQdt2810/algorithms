#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
            int minOps = 0;
            while (true){
                if (pq.size() < 2) break;
                long long x = pq.top(); pq.pop();
                if (x >= k) break;
                long long y = pq.top(); pq.pop();
                pq.push(2 * x + y);
                ++minOps;
            }
            return minOps;
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
    vector<int> nums = {97,73,5,78};
    int k = 98;

    cout << sol.minOperations(nums, k);

    return 0;
}