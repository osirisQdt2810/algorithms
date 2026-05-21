#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
private:
    struct Trie {
        struct Node {
            Node* child[10];
            // int prefix{0};

            Node(){
                for (int i = 0; i < 10; ++i){
                    child[i] = nullptr;
                }
            }
        };

        Node* root;

        Trie(){
            root = new Node();
        }

        vector<int> split(int num){
            vector<int> res;
            while (num){
                res.push_back(num % 10);
                num /= 10;
            }
            return res;
        }

        void insert(int num){
            vector<int> digits = split(num);
            Node* curr = root;
            for (int i = digits.size() - 1; i >= 0; --i){
                int c = digits[i];
                if (curr->child[c] == nullptr){
                    curr->child[c] = new Node();
                }
                // curr->prefix++;
                curr = curr->child[c];
            }
        }

        int query(int num){
            vector<int> digits = split(num);
            Node* curr = root;
            int len = digits.size();
            for (int i = len - 1; i >= 0; --i){
                int c = digits[i];
                if (curr->child[c] == nullptr){
                    return len - 1 - i;
                }
                curr = curr->child[c];
            }
            return len;
        }
    };

private:
    int length_prefix_common(int a, int b){
        vector<int> a_digits;
        vector<int> b_digits;
        while (a){
            a_digits.push_back(a % 10);
            a /= 10;
        }

        while (b){
            b_digits.push_back(b % 10);
            b /= 10;
        }
        std::reverse(a_digits.begin(), a_digits.end());
        std::reverse(b_digits.begin(), b_digits.end());

        int m = min(a_digits.size(), b_digits.size());
        int res = 0;
        for (int i = 0; i < m; ++i){
            if (a_digits[i] != b_digits[i]) break;
            ++res;
        }
        return res;
    }

public:
    int longestCommonPrefixBruteForce(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for (int x : arr1)
            for (int y : arr2)
                ans = max(ans, length_prefix_common(x, y));
        return ans;
    }

    int longestCommonPrefixTrie(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (auto a1 : arr1)
            trie.insert(a1);

        int ans = 0;
        for (auto a2 : arr2){
            ans = max(ans, trie.query(a2));
        }
        return ans;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        return longestCommonPrefixTrie(arr1, arr2);
    }
};


int main(){
    Solution sol;
    vector<int> arr1{1, 26};
    vector<int> arr2{22, 2};
    int ans = sol.longestCommonPrefix(arr1, arr2);
    cout << ans << "\n";
    return 0;
}