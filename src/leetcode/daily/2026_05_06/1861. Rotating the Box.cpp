#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
class Solution {
    public:
        vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
            using StationaryPos = int;
            using NumStone = int;
            using sn = pair<StationaryPos, NumStone>;
            
            int rows = boxGrid.size();
            int cols = boxGrid[0].size();
            std::vector<std::vector<sn>> sns(rows);
            for (int r = 0; r < rows; ++r){
                int stone_cnt = 0;
                for (int c = 0; c < cols; ++c){
                    if (boxGrid[r][c] == '*'){
                        sns[r].push_back({c, stone_cnt});
                        stone_cnt = 0;
                    }
                    else if (boxGrid[r][c] == '#'){
                        ++stone_cnt;
                    }
                }
                sns[r].push_back({cols, stone_cnt});
            }

            vector<vector<char>> res(cols, vector<char>(rows, '.'));
            for (int r = 0; r < rows; ++r){
                for (auto& [sp, ns] : sns[rows - r - 1]){
                    if (sp != cols) res[sp][r] = '*';
                    for (int j = 1; j <= ns; ++j)
                        res[sp-j][r] = '#';
                }
            }
            return res;
        }
};

int main(){
    Solution sol;

    vector<vector<char>> boxGrid = {{'#','#','#','#','#'},{'#','#','#','#','#'},{'#','#','#','#','#'},{'#','#','#','#','#'},{'#','#','#','#','#'}};
    sol.rotateTheBox(boxGrid);

    return 0;
}