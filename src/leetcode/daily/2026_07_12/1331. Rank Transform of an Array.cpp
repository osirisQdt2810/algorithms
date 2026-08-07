#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            if (arr.empty()) return arr;

            vector<int> uni = arr;
            sort(uni.begin(), uni.end());
            int sz = 1, n = arr.size();
            for (int r = 1; r < n; ++r){
                if (uni[r] == uni[sz-1]) continue;
                uni[sz++] = uni[r];
            }
            for (auto& num : arr){
                int l = 0, r = sz-1;
                while (l <= r){
                    int m = (l+r)/2;
                    if (num == uni[m]){
                        num = m+1;
                        break;
                    }
                    if (num < uni[m]){
                        r = m-1;
                    }
                    else {
                        l = m+1;
                    }
                }
            }
            return arr;
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