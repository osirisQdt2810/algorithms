#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_set<int> seen;
        int len = nums.size();
        int n = len - 1;
        int cnt_n = 0;
        for (auto& num : nums){
            if (num > n) return false;
            if (num == n){
                if (++cnt_n > 2){
                    return false;
                }
            }
            else if (seen.find(num) != seen.end()) return false;
            else {
                seen.insert(num);
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    return 0;
}