#include <vector>
#include <iostream>

using namespace std;

class Trie {
    private:
        struct Node {
            Node* child[26];
            int occurrence{0};
            int prefix_count{0};
            int index{-1};
        };

        Node* root;

        Node* _erase(Node* curr, const string& word, size_t len, size_t i){
            if (curr == nullptr) return nullptr;
            if (i == len){
                --curr->occurrence;
            }
            else {
                int c = word[i] - 'a';
                curr->child[c] = _erase(curr->child[c], word, len, i + 1);
            }
            if (curr != root){
                if (--curr->prefix_count == 0){
                    delete curr;
                    curr = nullptr;
                }
            }
            return curr;
        }

    public:
        Trie() : root(new Node()){}
        
        void insert(const string& word, int index) {
            Node* curr = root;
            for (auto c : word){
                int i = c - 'a';
                if (curr->child[i] == nullptr) curr->child[i] = new Node();
                curr = curr->child[i];
                ++curr->prefix_count;
            }
            ++curr->occurrence;
            curr->index = index;
        }
        
        bool search(const string& word) {
            Node* curr = root;
            for (auto c : word){
                int i = c - 'a';
                if (curr->child[i] == nullptr) return false;
                curr = curr->child[i];
            }
            return curr->occurrence;
        }
        
        bool startsWith(const string& prefix) {
            Node* curr = root;
            for (auto c : prefix){
                int i = c - 'a';
                if (curr->child[i] == nullptr) return false;
                curr = curr->child[i];
            }
            return curr->prefix_count;
        }

        void erase(const string& word){
            // must use recursion because we have only decided to delete current node T only if 
            // we have already determined the state of its childnode
            root = _erase(root, word, word.size(), 0);
        }
};

class Solution {
    private:
        int m, n;

        void swap(int& a, int& b, int& c, int& d){
            int t = a;
            a = d;
            d = c;
            c = b;
            b = t;
        }
        
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            Trie trie;
            size_t num_words = words.size();
            for (size_t i = 0; i < num_words; ++i){
                auto& word = words[i];
                trie.insert(word, i);
            }

            vector<string> res;
            m = board.size();
            n = board[0].size();
            
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    // start from cell(i, j)
                    dfs(i, j, m, n);
                }
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
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};

    Solution sol;
    for (auto r : sol.findWords(board, words))
        cout << r << " ";

    return 0;
}