#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ij;
typedef pair<ij, ij> ijij;

class Solution {
public:
    int minimum(int a, int b, int c, int d){
        return min(a, min(b, min(c, d)));
    }

    int maximum(int a, int b, int c, int d){
        return max(a, max(b, max(c, d)));
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        vector<ij> y_parallel;
        int N = points.size();
        for (int i = 0; i < N; ++i){
            for (int j = i + 1; j < N; ++j){
                if (points[i][1] == points[j][1]){
                    y_parallel.push_back({i, j});
                    // cout << "y_parallel: " << i << ", " << j << "\n";
                }
            }
        }

        int M = y_parallel.size();
        vector<ijij> xy_parallel;
        for (int i = 0; i < M; ++i){
            for (int j = i + 1; j < M; ++j){
                ij pair_1 = y_parallel[i];
                ij pair_2 = y_parallel[j];

                int i1 = pair_1.first, j1 = pair_1.second;
                int i2 = pair_2.first, j2 = pair_2.second;

                if (
                    points[i1][0] == points[i2][0] && points[j1][0] == points[j2][0] ||
                    points[i1][0] == points[j2][0] && points[j1][0] == points[i2][0]
                ){
                    xy_parallel.push_back({pair_1, pair_2});
                }
            }
        }

        int max_res = -1;
        for (auto& ijij : xy_parallel){
            int tl = ijij.first.first;
            int tr = ijij.first.second;
            int bl = ijij.second.first;
            int br = ijij.second.second;

            int xmin = minimum(points[tl][0], points[bl][0], points[tr][0], points[br][0]);
            int ymin = minimum(points[tl][1], points[bl][1], points[tr][1], points[br][1]);
            int xmax = maximum(points[tl][0], points[bl][0], points[tr][0], points[br][0]);
            int ymax = maximum(points[tl][1], points[bl][1], points[tr][1], points[br][1]);

            // cout << xmin << " " << xmax << " " << ymin << " " << ymax << "\n";
            bool stop = false;
            for (int i = 0; i < N; ++i){
                if (i == tl || i == tr || i == bl || i == br){
                    continue;
                }
                int x = points[i][0], y = points[i][1];
                if (
                    xmin <= x && x <= xmax && ymin <= y && y <= ymax
                ){
                    stop = true;
                    break;
                }
            }
            if (!stop){
                max_res = max(max_res, (xmax - xmin) * (ymax - ymin));
            }
        }
        return max_res;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    // vector<int> nums = {3,-2,1,1};
    // vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{2,2}};
    // vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3}};
    vector<vector<int>> points = {{100,80},{67,79},{100,79},{67,80},{80, 47}};

    Solution s;
    cout << s.maxRectangleArea(points) << "\n";
}