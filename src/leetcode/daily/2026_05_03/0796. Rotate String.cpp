#include <vector>
#include <iostream>
#include <string>

using namespace std;

static constexpr int M = 1e9 + 9;
static constexpr int P = 31;
using ll = long long;

struct HashString {
    vector<ll> h;
    size_t n;
    std::string& s;

    HashString(std::string& inp) : s(inp), n(inp.size()){
        h.assign(n + 1, 0);
        ll pow = 1;
        for (int i = 0; i < n; ++i){
            h[i + 1] = (h[i] + (s[i] - 'a' + 1) * pow) % M;
            pow = (pow * P) % M;
        }
    }

    ll hash(){
        return h[n];
    }

    ll hash(int i, int j){ 
        return (h[j + 1] - h[i] + M) % M; // ~hash[i...j] * P^i
    }
};

class Solution {
    public:
        bool rotateString(string s, string goal) {
            size_t s_len = s.size(), goal_len = goal.size();
            if (s_len != goal_len) return false;

            s += s;
            ll goal_hash = HashString(goal).hash();
            auto s_hash = HashString(s);

            ll pow = 1;
            for (int i = 0; i < s_len; ++i){
                ll hash_ij = s_hash.hash(i, i + s_len - 1);
                ll hash_goal = (goal_hash * pow) % M;

                if (hash_ij == hash_goal){
                    if (goal.compare(s.substr(i, s_len)) == 0){
                        return true;
                    }
                }

                pow = (pow * P) % M;
            }
            return false;
        }
};

auto init = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    std::string s = "abcde";
    std::string goal = "abced";
    std::cout << sol.rotateString(s, goal) << std::endl;
    return 0;
}