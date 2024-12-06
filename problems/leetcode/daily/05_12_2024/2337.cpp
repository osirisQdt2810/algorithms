#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> DI;  // Direction - Index
class Solution {
public:
    bool canChange2(string start, string target) {
        // 0: L, 1: R
        vector<DI> inStart, inTarget;

        for (int i = 0; i < start.size(); ++i){
            char c1 = start.at(i);
            char c2 = target.at(i);
            if (c1 == 'L'){
                inStart.push_back({0, i});
            }
            else if (c1 == 'R'){
                inStart.push_back({1, i});
            }

            if (c2 == 'L'){
                inTarget.push_back({0, i});
            }
            else if (c2 == 'R'){
                inTarget.push_back({1, i});
            }
        }

        if (inStart.size() != inTarget.size()){
            return false;
        }

        int N = inStart.size();
        for (int i = 0; i < N; ++i){
            int sType = inStart[i].first, sIndex = inStart[i].second;
            int tType = inTarget[i].first, tIndex = inTarget[i].second;
            if (sType != tType) return false;
            if (
                (sType == 0 && sIndex < tIndex) 
                || (sType == 1 && sIndex > tIndex)
            ){
                return false;
            }
        }

        return true;
    }

    bool canChange(string start, string target){
        int s_ptr = 0, t_ptr = 0, len = start.size();
        while (s_ptr < len || t_ptr < len){
            while (s_ptr < len && start[s_ptr] == '_') ++s_ptr;
            while (t_ptr < len && target[t_ptr] == '_') ++t_ptr;

            if (
                (s_ptr == len && t_ptr != len) ||
                (s_ptr != len && t_ptr == len) ||
                (start[s_ptr] != target[t_ptr])
            ){
                return false;
            }
            
            if (
                (start[s_ptr] == 'L' && s_ptr < t_ptr) ||
                (start[s_ptr] == 'R' && s_ptr > t_ptr)
            ){
                return false;
            }
            ++s_ptr;
            ++t_ptr;
        }
        return true;
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

    // string start = "_L__R__R_", target = "L______RR";
    string start = "R_L_", target = "__LR";
    // string start = "_R", target = "R_";


    cout << sol.canChange(start, target);

    return 0;
}