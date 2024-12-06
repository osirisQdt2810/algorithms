#include <bits/stdc++.h>

using namespace std;

#define NEG_CASE 0
#define MAXIMUM_ARRAY 1000100
#define OPERATOR(a, b) a + b                            
#define OPERATOR_UPDATE_IT(lazy, l, r) lazy * (r - l + 1)  // for sum: it += lazy * (r - l + 1), for min/max: it += lazy

using IT = int;

/**
 * @brief Traversal Order
 */
enum class Order {
    preorder,
    inorder,
    postorder
};

/**
 * @brief Definition for a binary tree node.
 */
template<typename IT>
class BTreeNode {
    private:
        void preOrderTraverse(BTreeNode<IT>* node, vector<IT>& its){
            if (node == nullptr) return;
            its.push_back(node->val);
            preOrderTraverse(node->left, its);
            preOrderTraverse(node->right, its);
        }

        void inOrderTraverse(BTreeNode<IT>* node, vector<IT>& its){
            if (node == nullptr) return;
            inOrderTraverse(node->left, its);
            its.push_back(node->val);
            inOrderTraverse(node->right, its);
        }

        void postOrderTraverse(BTreeNode<IT>* node, vector<IT>& its){
            if (node == nullptr) return;
            postOrderTraverse(node->left, its);
            postOrderTraverse(node->right, its);
            its.push_back(node->val);
        }

        size_t totalNode(const BTreeNode<IT>* node) const {
            if (node == nullptr) return 0;
            return totalNode(node->left) + totalNode(node->right) + 1;
        }

    public:
        IT val;
        BTreeNode<IT> *left;
        BTreeNode<IT> *right;
        BTreeNode() : val(0), left(nullptr), right(nullptr) {}
        BTreeNode(IT x) : val(x), left(nullptr), right(nullptr) {}
        BTreeNode(IT x, BTreeNode<IT> *left, BTreeNode<IT> *right) : val(x), left(left), right(right) {}

    public:
        vector<IT> traverse(Order order){
            vector<IT> res;
            switch (order){
                case Order::inorder:
                    inOrderTraverse(this, res);
                    break;
                
                case Order::preorder:
                    preOrderTraverse(this, res);
                    break;

                case Order::postorder:
                    postOrderTraverse(this, res);
                    break;

                default:
                    break;
            }
            return res;
        }

        size_t totalNode() const {
            return totalNode(this);
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
        IT query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < node[t].l || node[t].r < x) return NEG_CASE;
            if (x <= node[t].l && node[t].r <= y) return node[t].it;
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
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

        // query[x, y] in known range[lt, rt]
        IT query(int t, int x, int y){
            if (x > y) return NEG_CASE;
            if (y < node[t].l || node[t].r < x) return NEG_CASE;
            if (x <= node[t].l && node[t].r <= y) return node[t].it;
            down(t);
            return OPERATOR(query(2 * t, x, y), query(2 * t + 1, x, y));
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

template<typename IT>
class Tree {
    public:
        virtual void insert(IT key) = 0;

        virtual void remove(IT key) = 0;

        virtual bool find(IT key) = 0;

        virtual vector<int> traverse(Order order) = 0;

        virtual size_t size() = 0;
};

template<typename IT>
class BinarySearchTree : public Tree<IT>{
    private:
        using Node = BTreeNode<IT>;
        Node* root = nullptr;

    private:
        Node* _insert(Node* parent, IT key){
            if (parent == nullptr){
                return new Node(key);
            }
            if (parent->val < key){
                parent->right = _insert(parent->right, key);
            }
            if (parent->val > key){
                parent->left = _insert(parent->left, key);
            }
            return parent;
        }

        Node* _remove(Node* parent, IT key){
            if (parent == nullptr) return nullptr;
            if (parent->val < key){
                parent->right = _remove(parent->right, key);
            }
            else if (parent->val > key){
                parent->left = _remove(parent->left, key);
            }
            else {
                if (parent->left != nullptr && parent->right != nullptr){
                    Node* successor = _minimum(parent->right);
                    parent->val = successor->val;
                    parent->right = _remove(parent->right, successor->val);
                }
                else {
                    if (parent->left == nullptr && parent->right == nullptr)
                        return nullptr;

                    if (parent->left != nullptr)
                        return parent->left;

                    if (parent->right != nullptr)
                        return parent->right;                    
                }
            }
            return parent;
        }

        Node* _search(Node* parent, IT key){
            if (parent == nullptr) return nullptr;
            if (parent->val == key){
                return parent;
            }
            else if (parent->val < key){
                return _search(parent->right, key);
            }
            else {
                return _search(parent->left, key);
            }
        }

        Node* _minimum(Node* parent){
            Node* p = parent;
            while (p->left != nullptr)
                p = p->left;
            return p;
        }

        Node* _maximum(Node* parent){
            Node* p = parent;
            while (p->right != nullptr)
                p = p->right;
            return p;
        }

    public:
        BinarySearchTree(){}
        BinarySearchTree(const vector<IT>& arr){
            for (auto& ele : arr){
                root = _insert(root, ele);
            }
        }

        void insert(IT key) override {
            root = _insert(root, key);
        }

        void remove(IT key) override {
            root = _remove(root, key);
        }

        bool find(IT key) override {
            return (_search(root, key) != nullptr);
        }

        vector<IT> traverse(Order order) override {
            if (root == nullptr) return {};
            return root->traverse(order);
        }

        size_t size() override {
            return root->totalNode();
        }

        IT minimum(){
            auto node = _minimum(root);
            return (node == nullptr) ? 1e9 : node->val;  
        }

        IT maximum(){
            auto node = _maximum(root);
            return (node == nullptr) ? -1e9 : node->val;
        }
};