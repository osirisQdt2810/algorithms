#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isValidDistribution(vector<int>& quantities, int Q, int N){
            if (Q == 0) return false;
            int cnt = 0;
            // for_each(quantities.begin(), quantities.end(), [&](const int& q){
            //     cnt += ceil(1.0 * q / Q);
            // });
            for (int& q : quantities){   // changing from previous for_each to this simple loop makes the performance beating from 30 -> 70
                cnt += (q + Q - 1) / Q;
            }
            return cnt <= N;
        }

        int minimizedMaximum(int n, vector<int>& quantities) {
            // int min_T = 0, max_T = *max_element(quantities.begin(), quantities.end()), ans = -1;
            int min_T = 0, max_T = 1e5, ans = -1;   // changing from max_element to 1e5 makes the performance beating from 70->100

            while (min_T <= max_T){
                int mid_T = (min_T + max_T) / 2;

                if (isValidDistribution(quantities, mid_T, n)){
                    ans = mid_T;
                    max_T = mid_T - 1;
                }
                else {
                    min_T = mid_T + 1;
                }
            }
            return ans;
        }
};

int main(){
    // int n = 6;
    // vector<int> quantities = {11, 6};

    // int n = 7;
    // vector<int> quantities = {15, 10, 10};

    int n = 1;
    vector<int> quantities = {1};

    Solution s;
    cout << s.minimizedMaximum(n, quantities);
}
