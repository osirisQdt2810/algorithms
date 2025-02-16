#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool canMakeSubsequence2(string str1, string str2) {
        map<char, vector<int>> char2idx;
        int n1 = str1.size(), n2 = str2.size();
        for (int i = 0; i < n1; ++i){
            char c = str1.at(i);
            char d = (c == 'z') ? 'a' : (c + 1);
            char2idx[c].push_back(i);
            char2idx[d].push_back(i);
        }
        
        int lastChar;
        for (int i = 0; i < n2; ++i){
            char c = str2.at(i);
            if (char2idx.find(c) == char2idx.end()){
                return false;
            }
            if (i == 0){
                lastChar = char2idx[c][0];
                continue;
            }

            const auto& indexes = char2idx[c];
            int l = 0, r = indexes.size() - 1, ans = -1;

            while (l <= r){
                int m = (l + r) / 2;
                if (indexes[m] > lastChar){
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }

            if (ans == -1){
                return false;
            }
            lastChar = indexes[ans];
        }

        return true;

    }

    bool canMakeSubsequence(string str1, string str2) {
        int ptr1 = 0, ptr2 = 0;
        int n1 = str1.size(), n2 = str2.size();
        while (ptr2 < n2){
            char c2 = str2.at(ptr2);

            bool exist = false;
            while (ptr1 < n1){
                char c1 = str1.at(ptr1);
                char d1 = (c1 == 'z') ? 'a' : c1 + 1;
                if (c2 == c1 || c2 == d1){
                    ++ptr1;
                    ++ptr2;
                    exist = true;
                    break;
                }
                ++ptr1;
            }
            // cout << "ptr1 = " << ptr1 << " -> ptr2 = " << ptr2 << "\n";
            if (!exist){
                return false;
            }
        }

        return true;

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

    string str1 = "zc", str2 = "ad";

    cout << sol.canMakeSubsequence(str1, str2);

    return 0;
}