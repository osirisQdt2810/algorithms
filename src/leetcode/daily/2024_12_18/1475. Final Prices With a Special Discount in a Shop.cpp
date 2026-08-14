#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        vector<int> target(N);
        for (int i = N - 1; i >= 0; --i){
            target[i] = prices[i];
            for (int j = i + 1; j < N; ++j){
                if (prices[j] <= prices[i]){
                    target[i] -= prices[j];
                    break;
                }
            }
        }
        return target;
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

    vector<int> prices = {8, 4, 6, 2, 3};

    for (int p : sol.finalPrices(prices)){
        cout << p << " ";
    }
    cout << "\n";

    return 0;
}