#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            auto pos = haystack.find(needle);
            return (pos != string::npos) ? pos : -1;
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