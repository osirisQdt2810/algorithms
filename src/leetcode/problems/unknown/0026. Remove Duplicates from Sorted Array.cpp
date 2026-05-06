#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            if (n < 2) return n;

            int pos = 1, curr_val = nums[0], res = 1;
            while (true){
                while (pos < n && nums[pos] == curr_val) ++pos;
                if (pos == n) break;

                curr_val = nums[res] = nums[pos];
                ++res;
            }

            for (int i = 0; i < n; ++i)
                cout << nums[i] << " ";
            cout << "\n";

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
    
    return 0;
}