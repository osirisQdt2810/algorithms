#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE 0
#define MAXIMUM_ARRAY 1000100
#define OPERATOR(a, b) a + b                            
#define OPERATOR_UPDATE_IT(lazy, l, r) lazy * (r - l + 1)  // for sum: it += lazy * (r - l + 1), for min/max: it += lazy
using IT = int;                  

/**
 * @brief Support for two operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Query information in [x, y] (information: min, max, sum) in O(logN)
 * @note: Index run from 1->N
 */
#define OPR >=

class IndexMinMaxSegmentTree {
    private:
        struct Node {
            int l, r;
            int idx = -1;
            IT it;
        };

    private:
        Node node[4 * MAXIMUM_ARRAY];
        int leaf[MAXIMUM_ARRAY];

        void build(int t, int x, int y){
            node[t].l = x; 
            node[t].r = y; 
            node[t].it = NEG_CASE;

            if (x == y){
                leaf[x] = t;
                node[t].idx = x;
                return;
            }
            build(2 * t, x, (x + y) / 2);
            build(2 * t + 1, (x + y) / 2 + 1, y);
        }

        // query[x, y] in known range[lt, rt]
        pair<IT, int> query(int t, int x, int y){
            if (x > y) return {NEG_CASE, -1};
            if (y < node[t].l || node[t].r < x) return {NEG_CASE, -1};
            if (x <= node[t].l && node[t].r <= y) return {node[t].it, node[t].idx};
            auto ln = query(2 * t, x, y);
            auto rn = query(2 * t + 1, x, y);
            return (ln.first OPR rn.first) ? ln : rn;
        }
        
    public:
        IndexMinMaxSegmentTree(int n){
            build(1, 1, n);
        }


        // update a[i] = k 
        void update(int i, IT k){
            int t = leaf[i];
            node[t].it = k;
            while (t != 1){
                t /= 2;
                if (node[2 * t].it OPR node[2 * t + 1].it){
                    node[t].it = node[2 * t].it;
                    node[t].idx = node[2 * t].idx; 
                }
                else {
                    node[t].it = node[2 * t + 1].it;
                    node[t].idx = node[2 * t + 1].idx;  
                }
            }
        }

        // query[x, y] in known range[lt, rt]
        pair<IT, int> query(int l, int r){
            return query(1, l, r);
        }
};

/**
 * @brief Support for two operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Query information in [x, y] (information: min, max, sum) in O(logN)
 * @note: Index run from 1->N
 */
class SegmentTree {
    private:
        struct Node {
            int l, r;
            IT it;
        };

    private:
        Node node[4 * MAXIMUM_ARRAY];
        int leaf[MAXIMUM_ARRAY];

        void build(int t, int x, int y){
            node[t].l = x; 
            node[t].r = y; 
            node[t].it = NEG_CASE;

            if (x == y){
                leaf[x] = t;
                return;
            }
            build(2 * t, x, (x + y) / 2);
            build(2 * t + 1, (x + y) / 2 + 1, y);
        }

        // query[x, y] in known range[lt, rt]
        IT query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < node[t].l || node[t].r < x) return NEG_CASE;
            if (x <= node[t].l && node[t].r <= y) return node[t].it;
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
        }
        
    public:
        SegmentTree(int n){
            build(1, 1, n);
        }


        // update a[i] = k 
        void update(int i, IT k){
            int t = leaf[i];
            node[t].it = k;
            while (t != 1){
                t /= 2;
                node[t].it = OPERATOR(node[2 * t].it, node[2 * t + 1].it);
            }
        }

        // query[x, y] in known range[lt, rt]
        IT query(int l, int r){
            return query(1, l, r);
        }
};

/**
 * @brief Support for three operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Query information in [x, y] (information: min, max, sum) in O(logN)
 *        3. Update a[u->v] += k in O(logN)   
 * @note: Index run from 1->N
 */
class LazySegmentTree {
    private:
        struct Node {
            int l, r;
            IT it;
            IT lazy{0};
        };

    private:
        Node node[4 * MAXIMUM_ARRAY];
        int leaf[MAXIMUM_ARRAY];
        int n;

        void build(int t, int x, int y){
            node[t].l = x; 
            node[t].r = y; 
            node[t].it = NEG_CASE;

            if (x == y){
                leaf[x] = t;
                return;
            }
            build(2 * t, x, (x + y) / 2);
            build(2 * t + 1, (x + y) / 2 + 1, y);
        }

        void down(int t){
            IT lazy = node[t].lazy;
            node[t].lazy = 0;
            node[2 * t].lazy += lazy;
            node[2 * t + 1].lazy += lazy;
            node[2 * t].it += OPERATOR_UPDATE_IT(lazy, node[2 * t].l, node[2 * t].r);
            node[2 * t + 1].it += OPERATOR_UPDATE_IT(lazy, node[2 * t + 1].l, node[2 * t + 1].r);
        }

        // query[x, y] in known range[lt, rt]
        IT query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < node[t].l || node[t].r < x) return NEG_CASE;
            if (x <= node[t].l && node[t].r <= y) return node[t].it;
            down(t);
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
        }

    public:
        LazySegmentTree(){}
        LazySegmentTree(int n): n(n){
            build(1, 1, n);
        }


        // update a[u] = k 
        void update(int t, int u, IT k){
            int l = node[t].l, r = node[t].r;
            if (u < l || r < u) return;
            if (l == r){
                node[t].it = k;
                return;
            }
            down(t);
            update(2 * t, u, k);
            update(2 * t + 1, u, k);
            node[t].it = OPERATOR(node[2 * t].it, node[2 * t + 1].it);
        }

        // update a[u->v] += k from node t
        void update(int t, int u, int v, IT k){
            int l = node[t].l, r = node[t].r;
            if (r < u || v < l) return;
            if (u <= l && r <= v){
                node[t].it += OPERATOR_UPDATE_IT(k, l, r);
                node[t].lazy += k;
                return;
            }
            
            down(t);
            update(2 * t, u, v, k);
            update(2 * t + 1, u, v, k);
            node[t].it = OPERATOR(node[2 * t].it, node[2 * t + 1].it);
        }

        IT query(int l, int r){
            return query(1, l, r);
        }

        friend std::ostream& operator<<(std::ostream& os, const LazySegmentTree& tree) {
            os << "tree: \n";
            for (int id = 1; id <= tree.leaf[tree.n]; ++id){
                os << "\t- [" << tree.node[id].l << ", " << tree.node[id].r << "]\t(" << id << "): val = " << tree.node[id].it << ", lazy = " << tree.node[id].lazy << "\n";
            }
            os << "\n";
            
            return os;
        }         
};

/**
 * @brief Support for three operations:
 *        1. Update a[i] = k in O(logN)
 *        2. Update a[i] += k in O(logN)
 *        3. Update a[u->v] += k in O(logN)
 *        4. Query sum[l, r] in O(logN)
 * @note: Index run from 1->N
 */
struct FenwickTreeSum {
    private:
        vector<IT> bitA;  // binary indexed tree
        vector<IT> bitB;  // binary indexed tree
        int n;

    private:
        IT sum(vector<int>& bits, int idx) {
            IT ret = 0;
            while (idx > 0){
                ret += bits[idx];
                idx -= idx & -idx;
            }
            return ret;
        }

        // a[idx] += delta
        void add(vector<int>& bits, int idx, IT delta) {
            while (idx <= n){
                bits[idx] += delta;
                idx += idx & -idx;
            }
        }

    public:
        FenwickTreeSum(int m) : n(m+1){
            bitA.assign(n, 0);
            bitB.assign(n, 0);
        }

        IT sum(int idx) {
            // std::cout << "idx = " << idx << ", sum(bitA, idx) = " << sum(bitA, idx) << "\n";
            return (sum(bitA, idx) * idx) - sum(bitB, idx);
        }

        IT sum(int l, int r) {
            if (l > r) return 0;
            return sum(r) - sum(l - 1);
        }

        void update(int l, int r, IT delta) {
            add(bitA, l, delta);
            add(bitA, r + 1, -delta);
            add(bitB, l, delta * (l - 1));
            add(bitB, r + 1, -delta * r);
        }

        void update(int idx, IT k){
            IT cur_val = sum(idx, idx);
            update(idx, idx, k - cur_val);
        }
};

class AlphabetTrie {
    private:
        static const int NUMBER_ALPHABET_CHARACTERS = 26;

    private:
        struct Node {
            Node* child[NUMBER_ALPHABET_CHARACTERS];
            int occurences{0};         // có bao nhiêu xâu là xâu được thể hiện bởi đỉnh này
            int prefixCounter{0};      // có bao nhiêu xâu có tiền tố là xâu được thể hiện bởi đỉnh này

            Node(){
                for (int i = 0; i < NUMBER_ALPHABET_CHARACTERS; ++i)
                    child[i] = nullptr;
            }
        };

        Node* root;

    private:
        bool _erase(const string& s, Node* currNode, int index){
            if (index == static_cast<int>(s.size())){
                --currNode->occurences;
            }
            else {
                int _char = s[index] - 'a';
                bool _is_deleted_node = _erase(s, currNode->child[_char], index + 1);
                if (_is_deleted_node)
                    currNode->child[_char] = nullptr;
            }

            if (currNode != root){
                --currNode->prefixCounter;
                if (currNode->prefixCounter == 0){
                    delete currNode;
                    return true;
                }
            }
            return false;
        }

        void _traverse_preorder(Node* currNode, string& currString, vector<string>& res, bool ascendant){
            if (currNode == nullptr) return;
            for (int i = 0; i < currNode->occurences; ++i)
                res.push_back(currString);
            
            if (ascendant){
                for (int c = 0; c < NUMBER_ALPHABET_CHARACTERS; ++c){
                    if (currNode->child[c] != nullptr){
                        currString += (char)('a' + c);
                        _traverse_preorder(currNode->child[c], currString, res, ascendant);
                        currString.pop_back();
                    }
                }
            }
            else {
                for (int c = NUMBER_ALPHABET_CHARACTERS - 1; c >= 0; --c){
                    if (currNode->child[c] != nullptr){
                        currString += (char)('a' + c);
                        _traverse_preorder(currNode->child[c], currString, res, ascendant);
                        currString.pop_back();
                    }
                }
            }
        }

    public:
        AlphabetTrie() : root(new Node()){}

        void insert(const string& s){
            Node* p = root;
            for (char c : s){
                int index = c - 'a';
                if (p->child[index] == nullptr)
                    p->child[index] = new Node();

                p = p->child[index];
                ++p->prefixCounter;
            }
            ++p->occurences;
        }

        void erase(const string& s){
            if (!find(s)) return;
            _erase(s, root, 0);
        }

        bool find(const string& s){
            Node* p = root;
            for (char c : s){
                int index = c - 'a';
                if (p->child[index] == nullptr) return false;
                p = p->child[index];
            }
            return p->occurences;
        }

        vector<string> sort(bool ascendant = false){
            vector<string> res;
            std::string currString = "";
            _traverse_preorder(root, currString, res, ascendant);
            return res;
        }
};

class BinaryTrie {
    private:
        static inline const int MAX_LG = 12;

    private:
        struct Node {
            Node* child[2];
            int occurences{0};
            int counter{0};

            Node(){
                for (int i = 0; i < 2; ++i)
                    child[i] = nullptr;
            }
        };

        Node* root = nullptr;

    private:
        bool _erase(int num, Node* currNode, int i){
            if (i < 0){
                --currNode->occurences;
            }
            else {
                int ith = (num >> i) & 1;
                bool _is_deleted_node = _erase(num, currNode->child[ith], i - 1);
                if (_is_deleted_node)
                    currNode->child[ith] = nullptr;
            }

            if (currNode != root){
                --currNode->counter;
                if (currNode->counter == 0){
                    delete currNode;
                    return true;
                }
            }
            return false;
        }
        
    public:
        BinaryTrie() : root(new Node()){}

        void insert(int num){
            Node* p = root;
            for (int i = MAX_LG; i >= 0; --i){
                int ith = (num >> i) & 1;
                if (p->child[ith] == nullptr)
                    p->child[ith] = new Node();
                
                p = p->child[ith];
                ++p->counter;
            }
            ++p->occurences;
        }

        void erase(int num){
            if (!find(num)) return;
            _erase(num, root, MAX_LG);
        }

        bool find(int num){
            Node* p = root;
            for (int i = MAX_LG; i >= 0; --i){
                int ith = (num >> i) & 1;
                if (p->child[ith] == nullptr) return false;
                p = p->child[ith];
            }
            return p->occurences;
        }

        int max_xor(int num){
            Node* p = root;
            int res = 0;
            int i = MAX_LG;
            while (p){
                int c = (num >> i) & 1;
                if (p->child[1 ^ c] == nullptr){
                    p = p->child[c];
                }
                else {
                    res += 1 << i;
                    p = p->child[1^c];
                }
            }
            return res;
        }
};