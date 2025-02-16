#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string addSpaces2(string s, vector<int>& spaces) {
        for (int i = 0; i < spaces.size(); ++i){
            s.insert(s.begin() + spaces[i] + i, ' ');       // O(n) =>
        }                                                   // O(n * S)
        return s;
    }

    string addSpaces(string s, vector<int>& spaces) {
        string target = "";
        
        target.insert(
            target.end(),
            s.begin(),
            s.begin() + spaces[0]
        );
        for (int i = 1; i < spaces.size(); ++i){
            target += " ";
            target.insert(
                target.end(), 
                s.begin() + spaces[i - 1], 
                s.begin() + spaces[i]
            );
        }
        target += " ";
        target.insert(
            target.end(),
            s.begin() + spaces[spaces.size() - 1],
            s.end()
        );
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

    // string s = "LeetcodeHelpsMeLearn";
    // vector<int> spaces = {8,13,15};

    string s = "icodeinpython";
    vector<int> spaces = {1,5,7,9};

    // string s = "spacing";
    // vector<int> spaces = {0,1,2,3,4,5,6};

    cout << sol.addSpaces(s, spaces);

    return 0;
}