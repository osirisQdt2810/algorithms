#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        stack<int> digits;
        int numSetBit = 0;
        int totalBit = 0;

    public:
        void deserialize(int num, int numBit){
            if (num == 0){
                for (int i = 1; i <= totalBit - numBit; ++i){
                    digits.push(0);
                }
                return;
            }
            deserialize(num / 2, numBit + 1);
            if (num % 2 == 1){
                if (numSetBit == 0){
                    digits.push(0);
                }
                else {
                    --numSetBit;
                    digits.push(1);
                }
            }
            else {
                digits.push(num % 2);
            }
        }

        int minimizeXor(int num1, int num2) {
            while (num2){
                numSetBit += num2 % 2;
                num2 /= 2;
                ++totalBit;
            }
            
            deserialize(num1, 0);

            int res = 0, bit = 1;
            while (!digits.empty()){
                int digit = digits.top(); digits.pop();
                if (digit == 0 && numSetBit){
                    digit = 1;
                    --numSetBit;
                }

                res += bit * digit;
                bit *= 2;
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
    int num1 = 3, num2 = 5;
    cout << sol.minimizeXor(num1, num2);
    return 0;
}