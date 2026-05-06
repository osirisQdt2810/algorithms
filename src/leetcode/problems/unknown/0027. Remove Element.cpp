#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            for (auto it = nums.begin(); it != nums.end();){
                if (*it == val){
                    it = nums.erase(it);
                }
                else {
                    ++it;
                }
            }
            return nums.size();
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