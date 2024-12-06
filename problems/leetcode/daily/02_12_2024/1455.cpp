#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool _isPrefixOfWord(const string& word, const string& prefix){
        if (prefix.size() > word.size()) return false;
        for (int i = 0; i < prefix.size(); ++i){
            if (prefix.at(i) != word.at(i)){
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        string currWord = "";
        int currIndex = 1;
        sentence += " ";
        for (int i = 0; i < sentence.size(); ++i){
            char c = sentence.at(i);
            if (c == ' '){
                if (_isPrefixOfWord(currWord, searchWord)){
                    return currIndex; 
                }   
                currWord = "";
                ++currIndex;
                continue;
            }

            currWord += c;
        }
        return -1;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution s;

    string sentence = "i love eating burger", searchWord = "burg";
    // vector<vector<int>> grids = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout << s.isPrefixOfWord(sentence, searchWord);

    return 0;
}