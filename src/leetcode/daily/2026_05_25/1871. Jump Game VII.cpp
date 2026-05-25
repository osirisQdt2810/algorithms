#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> prefix(n+1, 0);
        prefix[1] = 1;
        /*
            The essence of the problem is: at index i, we need to check if there exists an index in the range [i-maxJump, i-minJump] that can be reached.
            Clearly, if we define dp[i] as whether index i can be reached (0 or 1), and if s[i] = '1', then dp[i] = 0.
            Therefore, we need to count how many indices in the range [i-maxJump, i-minJump] have dp[index] = 1.
            This counting problem can be efficiently solved using a prefix sum array, where prefix[i] represents the cumulative count of reachable indices up to index i.
            Thus, we can update prefix[i] by adding prefix[i-1] to it. Next, to determine if index i can be reached, we check if
            the sum of reachable indices in the range [l, r] (where l = i - maxJump and r = i - minJump) is greater than 0, which can be calculated as prefix[r] - prefix[l-1]. 
            If this condition is true, we will add 1 to prefix[i] to indicate that index i can be reached.
        */
        for (int i = 2; i <= n; ++i){
            prefix[i] += prefix[i-1];
            int r = i - minJump;
            int l = i - maxJump;
            if (s[i-1] != '0' || r < 1) continue;
            prefix[i] += (prefix[r] - prefix[max(0, l-1)] > 0);
            // cout << "i=" << i << " prefix=" << prefix[i] << ", l=" << l << ", r=" << r << ", prefix[r]=" << prefix[r] << ", prefix[l-1]=" << prefix[max(0, l-1)] << "\n";
        }
        return (prefix[n] - prefix[n-1]);
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
    string s = "01101110";
    cout << sol.canReach(s, 2, 3) << "\n"; // true

    return 0;
}