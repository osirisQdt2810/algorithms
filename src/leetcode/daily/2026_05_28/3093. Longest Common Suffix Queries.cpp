#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

struct Trie {
    struct Node {
        map<char, Node*> child; // use array child[26] or unordered_map return MLE
        int i{-1};
        size_t len{0};

        void update(int index, size_t size){
            if (i < 0 || len > size){
                i = index;
                len = size;
            }
        }
    };

    Node* root = nullptr;

    Trie() : root(new Node()){}

    void insert(int index, string& word){
        Node* curr = root;
        for (int i = word.size()-1; i >= 0; --i){
            int t = word[i] - 'a';
            if (curr->child.find(t) == curr->child.end()){
                curr->child[t] = new Node();
            }
            curr = curr->child[t];
            curr->update(index, word.size());
        }
    }

    int query(string& word){
        Node* curr = root;
        for (int i = word.size()-1; i >= 0; --i){
            int t = word[i] - 'a';
            if (curr->child.find(t) == curr->child.end()){
                break;
            }
            curr = curr->child[t];
        }
        return curr->i;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n_containers = wordsContainer.size();
        int n_queries = wordsQuery.size();

        Trie trie;
        int min_index = 0;
        for (int i = 0; i < n_containers; ++i){
            trie.insert(i, wordsContainer[i]);
            if (wordsContainer[i].size() < wordsContainer[min_index].size()){
                min_index = i;
            }
        }

        vector<int> res;
        for (auto& query : wordsQuery){
            int r = trie.query(query);
            res.push_back((r < 0) ? min_index : r);
        }

        return res;
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
    vector<string> wordsContainer = {"abcd","bcd","xbcd"}, wordsQuery = {"cd","bcd","xyz"};

    auto res = sol.stringIndices(wordsContainer, wordsQuery);
    for (auto& r : res)        cout << r << "\n";
    return 0;
}