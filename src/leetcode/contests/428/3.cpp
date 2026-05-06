#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxInd = events[0][0], maxDur = events[0][1];

        for (int i = 1; i < events.size(); ++i){
            int i1 = events[i-1][0], t1 = events[i-1][1];
            int i2 = events[i][0], t2 = events[i][1];
            if (maxDur < t2 - t1){
                maxDur = t2 - t1;
                maxInd = i2;
            }
            else if (maxDur == t2 - t1){
                maxInd = min(maxInd, i2);
            }
        }

        return maxInd;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){

}