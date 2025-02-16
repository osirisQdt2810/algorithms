#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool larger(const string& a, const string& b){
        int len_a = a.length(), len_b = b.length();
        int len = min(len_a, len_b);
        for (int i = 0; i < len; ++i){
            if (a[i] < b[i]) return false;
            if (a[i] > b[i]) return true;
        }
        return len_a >= len_b;
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string target = "";
        int n = word.length();

        for (int i = 0; i < n; ++i){
            int jmax = min(n - 1, n + i - numFriends);
            string currMaxStr = word.substr(i, jmax - i + 1);
            // if (larger(currMaxStr, target)){
            if (currMaxStr.compare(target) > 0){
                target = currMaxStr;
            }
            // cout << "i = " << i << " -> jmax = " << jmax << " -> currMaxStr = " << currMaxStr << " -> target = " << target << endl;
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
    string word = "dbca"; int numFriends = 2;
    // string word = "gh"; int numFriends = 1;
    Solution sol;
    cout << sol.answerString(word, numFriends);

    // cout << (sol.larger("gh", "h") ? "true" : "false");
    return 0;
}