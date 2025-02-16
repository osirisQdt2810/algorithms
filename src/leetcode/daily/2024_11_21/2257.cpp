#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        enum class State : uint8_t {
            guard,
            wall,
            unguarded,
            guarded
        };

    public:
        int countUnguarded2(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<bool>> mask(m, vector<bool>(n, false));

            for (auto& guard : guards)
                mask[guard[0]][guard[1]] = true;
            
            for (auto& wall : walls)
                mask[wall[0]][wall[1]] = true;

            for (auto& guard : guards){
                // find i: walls[i-1][0] < pt_x < walls[i][0] and walls[j][1] = guard[1]
                int l_x = -1, r_x = m;
                int l_y = -1, r_y = n;
                for (auto& wall : walls){
                    if (wall[1] == guard[1]){
                        if (guard[0] < wall[0]){
                            r_x = min(r_x, wall[0]);
                        }
                        else {
                            l_x = max(l_x, wall[0]);
                        }
                    }

                    else if (wall[0] == guard[0]){
                        if (guard[1] < wall[1]){
                            r_y = min(r_y, wall[1]);
                        }
                        else {
                            l_y = max(l_y, wall[1]);
                        }
                    }
                }
                
                for (int x = l_x + 1; x < r_x; ++x){
                    mask[x][guard[1]] = true;
                }

                for (int y = l_y + 1; y < r_y; ++y){
                    mask[guard[0]][y] = true;
                }

                // cout << "guard[0] = " << guard[0] << " -> l_x = " << l_x << " - r_x = " << r_x << "\n"; 
                // cout << "guard[1] = " << guard[1] << " -> l_y = " << l_y << " - r_y = " << r_y << "\n"; 
            }

            int counter = 0;
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    if (mask[i][j] == false){
                        ++counter;
                        // cout << "x = " << i << " - y = " << j << "\n";
                    }
                }
            }
            return counter;
        }
            
        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
            vector<vector<State>> states(m, vector<State>(n, State::unguarded));
            for (auto& guard : guards) states[guard[0]][guard[1]] = State::guard;
            for (auto& wall : walls) states[wall[0]][wall[1]] = State::wall;

            for (auto& guard : guards){
                int g_x = guard[0], g_y = guard[1];
                for (int x = g_x - 1; x >= 0; --x){
                    if (states[x][g_y] == State::guard || states[x][g_y] == State::wall) break;
                    states[x][g_y] = State::guarded;
                }

                for (int x = g_x + 1; x < m; ++x){
                    if (states[x][g_y] == State::guard || states[x][g_y] == State::wall) break;
                    states[x][g_y] = State::guarded;
                }        

                for (int y = g_y - 1; y >= 0; --y){
                    if (states[g_x][y] == State::guard || states[g_x][y] == State::wall) break;
                    states[g_x][y] = State::guarded;
                }      

                for (int y = g_y + 1; y < n; ++y){
                    if (states[g_x][y] == State::guard || states[g_x][y] == State::wall) break;
                    states[g_x][y] = State::guarded;
                }                                            
            }

            int counter = 0;
            for (int x = 0; x < m; ++x){
                for (int y = 0; y < n; ++y){
                    counter += (states[x][y] == State::unguarded);
                }
            }
            return counter;
        }
};