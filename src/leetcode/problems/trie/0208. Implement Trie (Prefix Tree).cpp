#include <vector>
#include <iostream>

using namespace std;

class Trie {
    private:
        struct Node {
            Node* child[26];
            int occurrence{0};
            int prefix_count{0};
        };

        Node* root;

    public:
        Trie() : root(new Node()){}
        
        void insert(string word) {
            Node* curr = root;
            for (auto c : word){
                int i = c - 'a';
                if (curr->child[i] == nullptr) curr->child[i] = new Node();
                curr = curr->child[i];
                ++curr->prefix_count;
            }
            ++curr->occurrence;
        }
        
        bool search(string word) {
            Node* curr = root;
            for (auto c : word){
                int i = c - 'a';
                if (curr->child[i] == nullptr) return false;
                curr = curr->child[i];
            }
            return curr->occurrence;
        }
        
        bool startsWith(string prefix) {
            Node* curr = root;
            for (auto c : prefix){
                int i = c - 'a';
                if (curr->child[i] == nullptr) return false;
                curr = curr->child[i];
            }
            return curr->prefix_count;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();