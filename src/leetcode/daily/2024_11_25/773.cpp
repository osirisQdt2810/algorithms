#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int toNum(int x1, int x2, int x3, int x4, int x5, int x6){
        return x1 * 100000 + x2 * 10000 + x3 * 1000 + x4 * 100 + x5 * 10 + x6;
    }

    string toString(int x1, int x2, int x3, int x4, int x5, int x6){
        return to_string(x1) + to_string(x2) + to_string(x3) + to_string(x4) + to_string(x5) + to_string(x6);
    }

    vector<int> adj(int x){
        int x1 = x / 100000;
        int x2 = x / 10000;
        int x3 = x / 1000;
        int x4 = x / 100;
        int x5 = x / 10;
        int x6 = x % 10;

        return {
            toNum(x2, x1, x3, x4,  x5, x6),
            toNum(x4, x2, x3, x1,  x5, x6),
            toNum(x1, x3, x2, x4,  x5, x6),
            toNum(x1, x5, x3, x4,  x2, x6),
            toNum(x1, x2, x3, x5,  x4, x6),
            toNum(x1, x2, x3, x4,  x6, x5),
            toNum(x1, x2, x6, x4,  x5, x3),
        };
    }

    vector<string> adj(string x){
        char x1 = x.at(0);
        char x2 = x.at(1);
        char x3 = x.at(2);
        char x4 = x.at(3);
        char x5 = x.at(4);
        char x6 = x.at(5);


        if (x1 == '0'){
            std::string a1 = {x2, x1, x3, x4,  x5, x6};
            std::string a2 = {x4, x2, x3, x1,  x5, x6};
            return {a1, a2};
        }

        else if (x2 == '0'){
            std::string a1 = {x2, x1, x3, x4,  x5, x6};
            std::string a3 = {x1, x3, x2, x4,  x5, x6};
            std::string a4 = {x1, x5, x3, x4,  x2, x6};
            return {a1, a3, a4};
        }

        else if (x3 == '0'){
            std::string a3 = {x1, x3, x2, x4,  x5, x6};
            std::string a7 = {x1, x2, x6, x4,  x5, x3};
            return {a3, a7};
        }

        else if (x4 == '0'){
            std::string a2 = {x4, x2, x3, x1,  x5, x6};
            std::string a5 = {x1, x2, x3, x5,  x4, x6};
            return {a2, a5};
        }

        else if (x5 == '0'){
            std::string a4 = {x1, x5, x3, x4,  x2, x6};
            std::string a5 = {x1, x2, x3, x5,  x4, x6};
            std::string a6 = {x1, x2, x3, x4,  x6, x5};
            return {a4, a5, a6};
        }

        else {
            std::string a6 = {x1, x2, x3, x4,  x6, x5};
            std::string a7 = {x1, x2, x6, x4,  x5, x3};
            return {a6, a7};
        }

    }

    int slidingPuzzle(vector<vector<int>>& board) {
        queue<string> Q;
        map<string, int> path;

        // cout << "here 0\n";

        string start = toString(board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2]);
        Q.push(start);
        path[start] = 0;

        // cout << "here 1\n";
        if (start == "123450"){
            return path[start];
        }

        while (!Q.empty()) {
            string x = Q.front(); Q.pop();

            auto adjs = adj(x);
            for (auto& y : adjs){
                if (path.find(y) == path.end()){
                    Q.push(y);
                    path[y] = path[x] + 1;

                    if (y == "123450"){
                        return path[y];
                    }
                }
            }
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
    vector<vector<int>> board = {{4,1,2}, {5,0,3}};

    Solution s;
    cout << s.slidingPuzzle(board);
    return 0;
}