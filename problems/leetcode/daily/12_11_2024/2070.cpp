#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int binarySearch(vector<vector<int>>& items, int q){
            int l = 0, r = items.size() - 1;
            int ans = -1;
            while (l <= r){
                int mid = (l + r) / 2;
                if (items[mid][0] <= q){
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return ans;
        }

        vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            sort(items.begin(), items.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
                return lhs[0] < rhs[0];
            });
            
            vector<int> maximums; maximums.resize(items.size()); 
            maximums[0] = items[0][1];
            for (size_t i = 1; i < items.size(); ++i){
                maximums[i] = max(maximums[i-1], items[i][1]);
            }

            vector<int> res;
            for (auto& q : queries){
                int targetIdx = binarySearch(items, q);
                res.push_back((targetIdx >= 0) ? maximums[targetIdx] : 0);
                // cout << "target = " << targetIdx << " " << maximums[targetIdx] << "\n";
            }
            return res;
        }
};

int main(){
    // vector<vector<int>> items {{1, 2},{1, 2},{1,3},{1,4}};
    // vector<int> queries {1};

    vector<vector<int>> items {{10, 1000}};
    vector<int> queries {5};

    Solution s;
    for (auto e : s.maximumBeauty(items, queries)){
        cout << e << " ";
    }

    return 0;

}