#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    std::map<std::string, int> splitAndCount(const std::string& s, int k) {
        std::map<std::string, int> result;
        int len = s.length();

        // Check if k is valid
        if (k <= 0 || len % k != 0) {
            // Handle invalid k (could throw an exception or return an empty map)
            return result; // Or consider throwing an exception
        }

        int subLen = len / k;

        // Split the string and count frequencies
        for (int i = 0; i < len; i += subLen) {
            std::string substring = s.substr(i, subLen);
            result[substring]++;
        }

        return result;
    }

    bool isPossibleToRearrange(string s, string t, int k) {
        auto s_map = splitAndCount(s, k);
        auto t_map = splitAndCount(t, k);

        if (s_map.size() != t_map.size()){
            return false;
        }

        for (auto it = s_map.begin(); it != s_map.end(); ++it){
            const string& key = it->first;
            int freq = it->second;

            if (t_map.find(key) == t_map.end() || t_map.at(key) != freq){
                return false;
            }
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
    Solution s;

}