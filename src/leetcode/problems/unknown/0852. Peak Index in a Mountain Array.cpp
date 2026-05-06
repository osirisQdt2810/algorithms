#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int l = 0, r = arr.size() - 1, ans = -1;
            while (l <= r){
                int m = (l + r) / 2;
                // cout << "l = " << l << " -> r = " << r << " -> m = " << m << "\n";
                if (m == 0 || m == arr.size() - 1) break;
                if (arr[m + 1] <= arr[m] && arr[m] <= arr[m - 1]){
                    r = m;
                }

                else if (arr[m - 1] <= arr[m] && arr[m] <= arr[m + 1]){
                    l = m;
                }
                else {
                    ans = m;
                    break;
                }
            }

            return ans;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();


int main(){
    vector<int> arr = {3, 4, 5, 1};

    Solution s;
    cout << s.peakIndexInMountainArray(arr);

    return 0;
}