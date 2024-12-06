#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n);
        for (auto& edge : edges){
            ++inDegrees[edge[1]];
        }

        int counter = 0;
        int target = -1;
        for (int i = 0; i < n; ++i){
            if (inDegrees[i] == 0){
                target = i;
                ++counter;
                if (counter >= 2){
                    return -1;
                }

            }
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
    int n = 4;
    vector<vector<int>> edges = {{0,1},{1,2}};

    Solution s;
    cout << s.findChampion(n, edges);
    return 0;
}