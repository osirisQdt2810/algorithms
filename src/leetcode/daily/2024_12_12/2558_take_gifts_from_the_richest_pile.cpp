#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        long long pickGifts2(vector<int>& gifts, int k) {
            int N = gifts.size();
            for (int i = 1; i <= k; ++i){
                int maxIdx = -1, maxGift = -1;
                for (int j = 0; j < N; ++j){
                    if (maxGift < gifts[j]){
                        maxGift = gifts[j];
                        maxIdx = j;
                    }
                }

                if (maxGift == 1)
                    break;

                gifts[maxIdx] = sqrt(maxGift);
            }

            long long sum = 0;
            for (auto& gift : gifts)
                sum += gift;
            return sum;
        }

        long long pickGifts(vector<int>& gifts, int k) {
            int N = gifts.size();
            priority_queue<int, vector<int>, less<int>> pq;
            long long sum = 0;
            for (auto& gift : gifts){
                sum += gift;
                pq.push(gift);
            }

            for (int i = 1; i <= k; ++i){
                int maxGift = pq.top(); pq.pop();
                if (maxGift == 1)
                    break;

                int leaving = sqrt(maxGift);
                sum -= (maxGift - leaving);
                pq.push(leaving);
                
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
    vector<int> gifts = {25,64,9,4,100};
    int k = 4;

    Solution sol;
    cout << sol.pickGifts(gifts, k);

    return 0;
}