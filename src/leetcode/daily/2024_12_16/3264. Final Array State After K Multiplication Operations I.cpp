#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, int> ii;

class Solution {
public:
    static inline const int K = 1e9 + 7;
    /**
     * @brief
     * 
     * @param num 
     * @param T 
     * @return int num^T % (10^9 + 7)
     */
    ll exp(ll num, int T){
        if (T == 0) return 1;
        auto div2 = exp(num, T / 2);
        if (T % 2 == 0) return (div2 * div2) % K;
        return ((((num % K) * div2) % K) * div2) % K;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1){
            for (auto& num : nums)
                num = num % K;
            return nums;
        }

        priority_queue<lli, vector<lli>, greater<lli>> minHeap;
        // vector<int> target; target.resize(nums.size());
        
        ll maxNum = -INT_MAX;
        for (int i = 0; i < nums.size(); ++i){
            maxNum = max(maxNum, (ll) nums[i]);
            minHeap.push({nums[i], i});
            // target[i] = nums[i];
        }

        while (maxNum >= multiplier * minHeap.top().first){
            auto [minNum, minIdx] = minHeap.top(); minHeap.pop();
            minHeap.push({multiplier * minNum, minIdx});
            nums[minIdx] = multiplier * minNum;
            --k;

            if (k == 0) return nums;
        }

        int currMinIdx = minHeap.top().second;
        vector<lli> newNums(nums.size());
        for (int i = 0; i < newNums.size(); ++i)
            newNums[i] = {nums[i], i};

        sort(newNums.begin(), newNums.end(), [](const lli& lhs, const lli& rhs){
            if (lhs.first < rhs.first) return true;
            else if (lhs.first == rhs.first) return lhs.second < rhs.second;
            return false;
        });

        // cout << "currMinIdx: " << currMinIdx << " -> k = " << k << "\n";
        // for (auto& num : newNums)
        //     cout << num.first << " " << num.second << "\n";
        // cout << "\n";

        int div = k / nums.size(), mod = k % nums.size();
        for (int i = 0; i < nums.size(); ++i){
            int T = div + (i <= mod - 1);
            // cout << "i = " << i << " T = " << T << " - newNums[i].first = " << newNums[i].first << " - newNums[i].second = " << newNums[i].second << "\n";
            nums[newNums[i].second] = ((newNums[i].first % K) * exp(multiplier, T)) % K;
        }

        // cout << "currMinIdx: " << currMinIdx << " -> k = " << k << "\n";
        // for (auto& num : nums)
        //     cout << num << " ";
        // cout << "\n";


        return nums;
    }

    vector<int> getFinalState2(vector<int>& nums, int k, int multiplier) {
        for (int i = 1; i <= k; ++i){
            int minIdx = -1, minNum = INT_MAX;
            for (int j = 0; j < nums.size(); ++j){
                if (nums[j] < minNum){
                    minNum = nums[j];
                    minIdx = j;
                }
            }
            nums[minIdx] *= multiplier;
        }
        return nums;
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

    // vector<int> nums = {2,1,3,5,6};
    // int k = 5, multiplier = 2;

    // vector<int> nums = {100000, 2000};
    // int k = 2, multiplier = 1000000;

    vector<int> nums = {4, 2, 4};
    int k = 3, multiplier = 2;

    sol.getFinalState(nums, k, multiplier);

    return 0;
}