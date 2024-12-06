#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
            int m = box.size(), n = box[0].size();
            vector<vector<char>> rotation(n, vector<char>(m));

            for (int i = 0; i < m; ++i){
                int prev_obs_pos = -1;
                int curr_obs_pos = -1;
                int num_box = 0;
                auto& row = box[i];

                for (int j = 0; j <= n; ++j){
                    if (j == n){
                        for (int k = n - 1; k >= curr_obs_pos + 1; --k){
                            rotation[k][m - 1 - i] = (k >= n - num_box) ? '#' : '.';
                        } 
                    }
                    else if (row[j] == '*'){
                        prev_obs_pos = curr_obs_pos;
                        curr_obs_pos = j;

                        // cout << "i = " << i << " j = " << j << " -> prev_obs_pos = " << prev_obs_pos << " -> curr_obs_pos = " << curr_obs_pos << " -> num_box = " << num_box << "\n";

                        rotation[curr_obs_pos][m - 1 - i] = '*';
                        for (int k = curr_obs_pos - 1; k >= prev_obs_pos + 1; --k){
                            rotation[k][m - 1 - i] = (k >= curr_obs_pos - num_box) ? '#' : '.';
                        } 

                        num_box = 0;
                    }

                    else if (row[j] == '#'){
                        ++num_box;
                    }
                }

                // // cout << "i = " << i << " -> obs_pos = " << obs_pos << " -> num_box = " << num_box << endl;
                // for (int j = 0; j < obs_pos; ++j){
                //     rotation[j][m - 1 -i] = (j < obs_pos - num_box) ? '.' : '#';
                // }
                // if (obs_pos < n){
                //     rotation[obs_pos][m - 1 -i] = '*';
                //     for (int j = obs_pos + 1; j < n; ++j){
                //         rotation[j][m - 1 -i] = row[j];
                //     }
                // }
            }

            return rotation;
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

    // vector<vector<char>> box = {{'#','.','#'}};
    vector<vector<char>> box = {{'#','.','*','.'},{'#','#','*','.'}};

    auto rot = s.rotateTheBox(box);

    for (auto& row : rot){
        for (auto& c : row){
            cout << c << " ";
        }
        cout << "\n";
    }
    return 9;
}