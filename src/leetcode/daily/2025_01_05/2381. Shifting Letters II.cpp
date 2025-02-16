#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        char doBackward(char c, int n){
            int offset = c - 'a';
            offset = (offset - n) % 26;
            offset = (offset + 26) % 26;  
            return static_cast<char>('a' + offset);        
        }

        char doForward(char c, int n){
            int offset = c - 'a';
            offset = (offset + n) % 26;   
            offset = (offset + 26) % 26;  
            return static_cast<char>('a' + offset);
        }
        
    public:
        string shiftingLetters(string s, vector<vector<int>>& shifts) {
            int n = s.size();
            vector<int> pos(n + 1, 0), neg(n + 1, 0);
            for (int i = 0; i < shifts.size(); ++i){
                int start = shifts[i][0], end = shifts[i][1], direction = shifts[i][2];
                if (direction == 0){
                    ++neg[start];
                    --neg[end + 1];
                }
                else {
                    ++pos[start];
                    --pos[end + 1];
                }
            }

            string target = "";
            for (int i = 0; i < n; ++i){
                if (i >= 1){
                    pos[i] += pos[i-1];
                    neg[i] += neg[i-1];
                }

                int forward = pos[i] - neg[i];
                // cout << "i = " << i << " -> c = " << s[i] << " -> forward = " << forward <<  " -> pos = " << pos[i] << " -> neg = " << neg[i] << "\n";
                if (forward < 0)
                    target += doBackward(s[i], -forward);
                else
                    target += doForward(s[i], forward);
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
    // string boxes = "110";
    // string s = "abc";
    // vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};

    string s = "xuwdbdqik";
    vector<vector<int>> shifts = {{4,8,0},{4,4,0},{2,4,0},{2,4,0},{6,7,1},{2,2,1},{0,2,1},{8,8,0},{1,3,1}};

    Solution sol;
    cout << sol.shiftingLetters(s, shifts);
    return 0;
}