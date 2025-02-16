#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int min_abs = INT_MAX;
        int num_neg = 0;
        long long sum_num = 0;

        for (auto& row : matrix){
            for (auto& num : row){
                if (num == 0){
                    --num_neg;
                }
                else if (num < 0){
                    ++num_neg;
                }

                int abs_num = abs(num);
                sum_num += abs_num;
                min_abs = min(min_abs, abs_num);
            }
        }

        if (num_neg % 2 == 0 || num_neg < 0){
            return sum_num;
        }
        else {
            return sum_num - 2 * min_abs;
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    // vector<vector<int>> matrix = {{-1, 0, -1},{-2,1,3},{3,2,2}};

    Solution s;
    cout << s.maxMatrixSum(matrix);

}