#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = 0;
        int ans = INT_MAX;
        while (l < m && r < n){
            if (nums1[l] == nums2[r]){
                ans = min(ans, nums1[l]);
                ++l;
                ++r;
            }
            else if (nums1[l] < nums2[r]){
                ++l;
            }
            else {
                ++r;
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};