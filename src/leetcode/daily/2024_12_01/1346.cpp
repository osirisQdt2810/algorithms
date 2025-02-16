#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> group;

        for (int& ele : arr){
            if (group.find(ele) != group.end()){
                return true;
            }

            if (ele % 2 == 0){
                group.insert(ele / 2);
            }

            group.insert(ele * 2);
        }

        return false;
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

    vector<int> arr = {10,2,5,3};

    cout << s.checkIfExist(arr);

    return 0;
}