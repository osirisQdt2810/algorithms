#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
            map<string, int> patternFreqs;

            for (auto& row : matrix) {
                string pattern = "";
                for (int col = 0; col < row.size(); ++col){
                    if (row[col] == row[0]){
                        pattern += 'T';
                    }
                    else {
                        pattern += 'F';
                    }
                }

                if (patternFreqs.find(pattern) != patternFreqs.end()){
                    ++patternFreqs[pattern];
                }
                else {
                    patternFreqs[pattern] = 1;
                }
            }

            int res = 0;
            for (auto it = patternFreqs.begin(); it != patternFreqs.end(); ++it){
                res = max(res, it->second);
            }
            return res;
        }
};