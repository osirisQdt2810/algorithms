// #include <iostream>
// #include <memory>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

int n;
string s, bad_letters;
int k;
int bl[26];
using hv = unsigned long long;
using ii = pair<int, int>;

struct Trie {
    struct Node {
        Node* child[26];
    };

    Node* root = nullptr;
    Node* curr = nullptr;

    Trie(){
        root = new Node();
        curr = root;
    }

    bool insert_char(int index){
        bool res = (curr->child[index] == nullptr);
        if (res) curr->child[index] = new Node();
        curr = curr->child[index];
        return res;
    }

    void reset(){
        curr = root;
    }
};

void trie_solve(){
    int res = 0;
    Trie trie;
    for (int l = 0; l < n; ++l){
        int cnt_bl = 0;
        trie.reset();
        for (int r = l; r < n; ++r){
            int index = s[r] - 'a';
            cnt_bl += bl[index];
            if (cnt_bl <= k){
                res += trie.insert_char(index);
            }
            else {
                break;
            }
        }
    }
    cout << res << "\n";
}

void hash_string_solve(){
    static constexpr int P = 31;
    static constexpr int M = 1e9 + 9;

    int res = 0;
    unordered_map<hv, std::vector<ii>> hash2str;    // -> use it still causes MLE -> use double hash
    for (int l = 0; l < n; ++l){
        int bl_cnt = 0;
        hv hash = 0;
        for (int r = l; r < n; ++r){
            bl_cnt += (bl[s[r] - 'a']);
            if (bl_cnt > k) break;
            // find hash(s[l...r]), check if hash(s[l...r]) in set or not.
            // hash(s[l...r]) = s[l] * p^(r-l) + s[l+1] * p^(r-l-1) + ... + s[r] * p^0
            // hash(s[l...r+1]) = s[l] * p^(r+1-l) + s[l+1] * p^(r-l) + ... + s[r+1] * p^0 = hash(s[l...r]) * p + s[r+1]
            hash = (hash * P + s[r] - 'a' + 1) % M;
            auto substr = s.substr(l, r - l + 1);
            if (hash2str.find(hash) == hash2str.end()){
                hash2str[hash] = {{l, r}};
                ++res;
            }
            else {
                auto& vec = hash2str.at(hash);
                // check if substr in vec or not. 
                // if yes => continue the next iteration of r
                // otherwise => ++res and push to the vector
                bool is_existed = false;
                for (auto& [i, j] : vec){
                    if (s.substr(i, j - i + 1).compare(substr) == 0){
                        is_existed = true;
                        break;
                    }
                }
                if (!is_existed){
                    ++res;
                    vec.push_back({l, r});
                }
            }
        }
    }
    cout << res << "\n";
}

void double_hash_string_solve(){
    static constexpr int P1 = 31;
    static constexpr int P2 = 37;
    static constexpr int M1 = 1e9 + 9;
    static constexpr int M2 = 1e9 + 7;

    int res = 0;
    unordered_set<hv> seen;    // -> use it still causes MLE -> use double hash
    for (int l = 0; l < n; ++l){
        int bl_cnt = 0;
        hv h1 = 0, h2 = 0;
        for (int r = l; r < n; ++r){
            bl_cnt += (bl[s[r] - 'a']);
            if (bl_cnt > k) break;
            // find h(s[l...r]), check if h(s[l...r]) in set or not.
            // h(s[l...r]) = s[l] * p^(r-l) + s[l+1] * p^(r-l-1) + ... + s[r] * p^0
            // h(s[l...r+1]) = s[l] * p^(r+1-l) + s[l+1] * p^(r-l) + ... + s[r+1] * p^0 = h(s[l...r]) * p + s[r+1]
            h1 = (h1 * P1 + s[r] - 'a' + 1) % M1;
            h2 = (h2 * P2 + s[r] - 'a' + 1) % M2;
            hv h = (h1 << 32) ^ h2;
            if (seen.find(h) == seen.end()){
                ++res;
                seen.insert(h);
            }
        }
    }
    cout << res << "\n";
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif

    cin >> s >> bad_letters >> k;
    n = s.size();
    for (int i = 0; i < 26; ++i)
        bl[i] = ('1' - bad_letters[i]);

    double_hash_string_solve();
    return 0;
}