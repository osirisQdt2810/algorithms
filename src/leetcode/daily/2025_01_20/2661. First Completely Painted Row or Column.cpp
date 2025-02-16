#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
            using ii = pair<int, int>;
            int m = mat.size(), n = mat[0].size();
            vector<int> row(m, n), col(n, m);
            unordered_map<int, ii> v2p;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    v2p[mat[i][j]] = {i, j};

            for (int T = 0; T < m * n; ++T){
                auto [i, j] = v2p[arr[T]];
                --row[i];
                --col[j];
                if (row[i] == 0 || col[j] == 0)
                    return T;
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
    Solution sol;
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
    cout << sol.firstCompleteIndex(arr, mat);
    return 0;
}