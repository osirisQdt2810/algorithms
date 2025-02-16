#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minOperations2(string boxes) {
        int n = boxes.size();
        vector<int> target(n, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                target[i] += (boxes[j] == '1') ? abs(j - i) : 0;
            }
        }
        return target;
    }

    vector<int> minOperations(string boxes){
        int n = boxes.size();
        vector<int> target(n, 0);        
        vector<int> count(n + 1, 0);
        vector<int> sum(n + 1, 0);

        for (int i = 0; i < n; ++i){
            if (boxes[i] == '1'){
                count[i + 1] = count[i] + 1;
                sum[i + 1] = sum[i] + i;
            }
            else {
                count[i + 1] = count[i];
                sum[i + 1] = sum[i];
            }
        }

        for (int i = 1; i <= n; ++i){
            int left = count[i-1] * (i - 1) - sum[i-1];
            int right = (sum[n] - sum[i]) - (count[n] - count[i]) * (i - 1);
            target[i-1] = left + right;

            // cout << "i = " << i << " -> count = " << count[i] << " -> sum = " << sum[i] << " -> target = " << target[i] << "\n";
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
    // string boxes = "110";
    string boxes = "001011";

    Solution sol;
    for (auto s : sol.minOperations(boxes))
        cout << s << " ";

    return 0;
}