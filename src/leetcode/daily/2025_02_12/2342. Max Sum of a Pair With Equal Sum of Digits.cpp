#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        using SelectionPair = vector<int>;
        using DigitSum = int;

        int select(int num, SelectionPair& old){
            if (old.size() == 1){
                old.push_back(num);
                return num + old[0];
            }
            else {
                int num1 = old[0], num2 = old[1];
                int minNum = std::min(num1, num2), maxNum = std::max(num1, num2);
                if (minNum < num){
                    old = {maxNum, num};
                }
                return old[0] + old[1];
            }
        }

        DigitSum sumDigits(int num){
            DigitSum sum = 0;
            while (num){
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }

    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<DigitSum, SelectionPair> d2s;
            int target = -1;
            for (auto& num : nums){
                DigitSum dSum = sumDigits(num);
                if (d2s.find(dSum) == d2s.end())
                    d2s[dSum].push_back(num);
                else
                    target = max(target, select(num, d2s[dSum]));
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
    vector<int> nums = {18,43,36,13,7};

    cout << sol.maximumSum(nums);

    return 0;
}