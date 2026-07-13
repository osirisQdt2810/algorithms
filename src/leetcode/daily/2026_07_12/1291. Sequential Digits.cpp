#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;

class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            int l = floor(log10(low))+1, h = floor(log10(high))+1;
            int start = 0, offset = 0;
            for (int d = 1; d <= l; ++d){
                start *= 10; start += d;
                offset *= 10; ++offset;
            }

            vector<int> res;
            for (int d, num, i = 0; i <= h - l; ++i){
                // cout << l << " " << start << " " << offset << " \n";
                num = start;
                while (num % 10){
                    if (num >= low && num <= high){
                        res.push_back(num);
                    }
                    num += offset;
                }

                d = start % 10 + 1;
                if (d == 10) break;
                start *= 10; start += d;
                offset *= 10; ++offset;
            }
            return res;
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

    return 0;
}