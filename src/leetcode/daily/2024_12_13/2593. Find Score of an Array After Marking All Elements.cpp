#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

class Solution {
public:
    long long findScore2(vector<int>& nums) {
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        unordered_set<int> marked;

        for (int i = 0; i < nums.size(); ++i)
            pq.push({nums[i], i});

        long long sum = 0;
        while (!pq.empty()){
            auto [num, u] = pq.top(); pq.pop();
            if (marked.find(u) != marked.end()) continue;

            sum += num;
            if (u > 0 && marked.find(u - 1) == marked.end()) marked.insert(u - 1);
            if (u < nums.size() - 1 && marked.find(u + 1) == marked.end()) marked.insert(u + 1);
        }

        return sum;
    }

    long long findScore(vector<int>& nums) {
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        vector<bool> marked(nums.size(), false);

        for (int i = 0; i < nums.size(); ++i)
            pq.push({nums[i], i});

        long long sum = 0;
        while (!pq.empty()){
            auto [num, u] = pq.top(); pq.pop();
            if (marked[u]) continue;

            sum += num;
            marked[u] = true;
            if (u > 0) marked[u - 1] = true;
            if (u < nums.size() - 1) marked[u + 1] = true;
        }

        return sum;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // string s = "aaaa";
    vector<int> nums = {2,1,3,4,5,2};

    Solution sol;
    cout << sol.findScore(nums);

    return 0;
}