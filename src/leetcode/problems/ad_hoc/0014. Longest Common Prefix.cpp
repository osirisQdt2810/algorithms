#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) return "";
            if (strs.size() == 1) return strs[0];

            string res = "";
            int n = strs.size();
            int min_len = INT_MAX;
            for (auto& str : strs) min_len = min(min_len, (int)str.size());

            for (int i = 0; i < min_len; ++i){
                char c = strs[0][i];
                bool common_char = true;
                for (int k = 1; k < strs.size(); ++k){
                    if (strs[k][i] != c){
                        common_char = false;
                        break;
                    } 
                }

                if (!common_char) break;
                
                res += c;
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

    return 0;
}