#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> repeats;
        for (char c = 'a'; c <= 'z'; c++) repeats[c] = 0;
        for (char& c : s) ++repeats[c];

        // for (char c = 'a'; c <= 'z'; c++)
        //     if (repeats[c] > 0)
        //         cout << "char = " << c << " - r = " << repeats[c] << "\n";

        string res = "";
        while (true){
            bool isZero = true;
            for (char c = 'z'; c >= 'a'; --c){
                if (repeats[c] > 0){
                    // cout << "before: char = " << c << " - r = " << repeats[c] << "\n";
                    int takeaway = 0;
                    if (repeats[c] <= repeatLimit) {
                        takeaway = repeats[c];
                        repeats[c] = 0;
                    }
                    else {
                        repeats[c] -= repeatLimit;
                        takeaway = repeatLimit;
                    }
                    string newStr(takeaway, c);
                    res.insert(res.end(), newStr.begin(), newStr.end());
                    // cout << "\tchar = " << c << ": r = " << repeats[c] <<  " - takeaway " << takeaway << " : newStr = " << newStr << " - res = " << res << endl;
                    isZero = false;
                }
            }

            if (isZero) break;
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

    string s = "cczazcc"; int repeatLimit = 3;

    cout << sol.repeatLimitedString(s, repeatLimit);

    return 0;
}