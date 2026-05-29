#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int sum = 1e5;

        for (auto& num : nums){
            int ele_sum = 0;
            while (num){
                ele_sum += num % 10;
                num /= 10;
            }
            sum = min(sum, ele_sum);
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
    Solution sol;
    return 0;
}