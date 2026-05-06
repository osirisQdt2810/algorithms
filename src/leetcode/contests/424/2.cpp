#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:

        // find j min: i >= Q[j][0]
        int binarySearch(const vector<vector<int>>& queries, int idx){
            int l = 0, r = queries.size() - 1, ans = -1;
            // cout << "binarySearch: idx = " << idx << " - l = " << l << " - r = " << r << "\n";
            while (l <= r){
                int m = (l + r) / 2;
                // cout << "m = " << m << " - l = " << l << " - r = " << r << " - value = " << queries[m][0] << " - idx = " << idx << "\n";
                if (idx >= queries[m][0]){
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            
            return ans;
        }

        bool isZeroArray2(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int> freqs(nums.size());

            // cout << "h1\n";
            sort(queries.begin(), queries.end(), [](const vector<int>& lhs, const vector<int>& rhs){
                return lhs[0] > rhs[0];
            });

            // cout << "h2\n";

            // for (auto Q : queries){
            //     cout << "Q: [" << Q[0] << ", " << Q[1] << "]" << "\n";
            // }
            // cout << "\n";

            for (int i = 0; i < nums.size(); ++i){
                int Q0_Index = binarySearch(queries, i);

                if (Q0_Index >= 0){
                    for (int j = Q0_Index; j < queries.size(); ++j){
                        if (i <= queries[j][1]){
                            freqs[i]++;
                        }
                    }
                }

                // cout << "i = " << i << " - Q0_index = " << Q0_Index << "\n";
                // cout << "\n\n";                
            }

            // for (int i = 0; i < static_cast<int>(nums.size()); ++i){
            //     cout << "arr[" << i << "] = " << nums[i] << " - freqs = " << freqs[i] << endl;
            // }

            for (int i = 0; i < static_cast<int>(nums.size()); ++i){
                if (freqs[i] < nums[i]){
                    return false;
                }
            }
            return true;
        }

        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int> freqs(nums.size() + 1, 0);

            // cout << "h2\n";

            // for (auto Q : queries){
            //     cout << "Q: [" << Q[0] << ", " << Q[1] << "]" << "\n";
            // }
            // cout << "\n";

            for (auto& Q: queries){
                ++freqs[Q[0]];
                --freqs[Q[1] + 1];
            }

            for (int i = 0; i < static_cast<int>(nums.size()); ++i){
                freqs[i] = (i > 0) ? (freqs[i - 1] + freqs[i]) : freqs[i];
                if (freqs[i] < nums[i]){
                    return false;
                }
            }
            return true;
        }
};