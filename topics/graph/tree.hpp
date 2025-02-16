#include <bits/stdc++.h>

using namespace std;

using IT = int;                  

template<typename IT>
class Tree {
    public:
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
        class BTreeNode {
            private:
                void preOrderTraverse(BTreeNode* node, vector<IT>& its){
                    if (node == nullptr) return;
                    its.push_back(node->val);
                    preOrderTraverse(node->left, its);
                    preOrderTraverse(node->right, its);
                }

                void inOrderTraverse(BTreeNode* node, vector<IT>& its){
                    if (node == nullptr) return;
                    inOrderTraverse(node->left, its);
                    its.push_back(node->val);
                    inOrderTraverse(node->right, its);
                }

                void postOrderTraverse(BTreeNode* node, vector<IT>& its){
                    if (node == nullptr) return;
                    postOrderTraverse(node->left, its);
                    postOrderTraverse(node->right, its);
                    its.push_back(node->val);
                }

                size_t totalNode(const BTreeNode* node) const {
                    if (node == nullptr) return 0;
                    return totalNode(node->left) + totalNode(node->right) + 1;
                }

            public:
                IT val;
                int height;
                BTreeNode *left;
                BTreeNode *right;
                BTreeNode() : val(0),  height(1), left(nullptr), right(nullptr) {}
                BTreeNode(IT x) : val(x),  height(1), left(nullptr), right(nullptr) {}
                BTreeNode(IT x, BTreeNode *left, BTreeNode *right) : val(x),  height(1), left(left), right(right) {}

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

    public:
        virtual void insert(IT key) = 0;

        virtual void remove(IT key) = 0;

        virtual bool find(IT key) = 0;

        virtual vector<IT> traverse(Order order) = 0;

        virtual size_t size() = 0;
};

template<typename IT>
class BinarySearchTree : public Tree<IT>{
    protected:
        using Node = typename Tree<IT>::BTreeNode;
        Node* root = nullptr;

    protected:
        virtual Node* _insert(Node* parent, IT key){
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

        virtual Node* _remove(Node* parent, IT key){
            cout << "hello 5\n";
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

        vector<IT> traverse(typename Tree<IT>::Order order) override {
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

template<typename IT>
class AVLTree : public BinarySearchTree<IT> {
    private:
        using typename BinarySearchTree<IT>::Node;

    protected:
        int _height(Node* node){
            if (node == nullptr) return 0;
            return node->height;
        }

        int _balance(Node* node){
            if (node == nullptr) return 0;
            return _height(node->left) - _height(node->right);
        }

        /**
         * @brief rotate tree from left to right, which w
         * 
         *           z                   y
         *          / \                 / \ 
         *         y   P    ------>    M   z  
         *        / \                     / \ 
         *       M   N                   N   P
         */
        Node* _rotateRight(Node* z){
            Node* y = z->left;
            Node* N = y->right;

            y->right = z;
            z->left = N;
            y->height = 1 + max(_height(y->left), _height(y->right));
            z->height = 1 + max(_height(z->left), _height(z->right));
            return y;
        }

        /**
         * @brief rotate tree from left to right, which w
         *           z                   y
         *          / \                 / \ 
         *         M   y    ------>    z   P 
         *            / \             / \   
         *           N   P           M   N 
         */
        Node* _rotateLeft(Node* z){
            Node* y = z->right;
            Node* N = y->left;
            y->left = z;
            z->right = N;
            y->height = 1 + max(_height(y->left), _height(y->right));
            z->height = 1 + max(_height(z->left), _height(z->right));
            return y;
        }

        Node* _insert(Node* parent, IT key) override {
            if (parent == nullptr) return new Node(key);
            if (parent->val == key) return parent;
            
            if (parent->val < key)
                parent->right = _insert(parent->right, key);
            
            if (parent->val > key)
                parent->left = _insert(parent->left, key);
            
            // Balance the node* `parent`
            parent->height = 1 + max(_height(parent->left), _height(parent->right));
            int balance = _balance(parent);

            /*
                There are two main cases that could happen to this node *parent.
                 1. Case 1: Tree is unbalanced in left-side (balance > 1)
                            z --> parent
                           / \ 
                          y   P
                         / \
                        Y1 Y2
                    In this first case, we have known that (by recursion) `y` is balanced, and `z` (parent) is unbalanced in left-side. So,
                    the inserted node (with key valued `key`) caused the unbalanced may be in `Y1` or `Y2`, corresponding to two subcases 
                    1.1 and 1.2 in the following.
                    
                 2. Case 2: Tree is unbalanced in right-side (balance < -1)
                            z --> parent
                           / \ 
                          M   y
                             / \
                            Y1 Y2
                    In this second case, we have known that (by recursion) `y` is balanced, and `z` (parent) is unbalanced in right-side. So,
                    the inserted node (with key valued `key`) caused the unbalanced may be in `Y1` or `Y2`, corresponding to two subcases 
                    2.1 and 12.2 in the following.
            */

            /*
             * @brief case 1.1, the inserted node cause unbalancing for parent `z` places in `Y1` <=> Left Left Side case
                            z --> parent                                                y     
                           / \                                                         / \
                          y   P                 Right Rotate on node z                x   z
                         / \                ------------------------------>          / \ / \
                        x  Y2                                                       M  N Y2 P 
                       / \
                      M   N --> the inserted will be in (x, M or N)
             */
            if (balance > 1 && parent->left->val > key)
                return _rotateRight(parent);
                                                 
            /*
             * @brief case 1.2, the inserted node cause unbalancing for parent `z` places in `Y2` <=> Left Right Side case
                            z --> parent                                                z                                                    x
                           / \                                                         / \                                                  / \
                          y   P                    Left Rotate on node y              x   P              Right Rotate on node z            y   z
                         / \                  ------------------------------>        / \            ------------------------------>       / \ / \                           
                        Y1  x                                                       y   N                                                Y1 M N  P
                           / \                                                     / \              
                          M   N --> the inserted will be in (x, M or N)           Y1  M             
             */
            if (balance > 1 && parent->left->val < key){
                parent->left = _rotateLeft(parent->left);
                return _rotateRight(parent);
            }

            /*
             * @brief case 2.1, the inserted node cause unbalancing for parent `z` places in `Y2` <=> Right Right Side case
                            z --> parent                                                    y     
                           / \                                                             / \
                          M   y                     Left Rotate on node z                 z   x
                             / \                ------------------------------>          / \ / \
                            Y1  x                                                       M Y1 N  P 
                               / \
                              N   P --> the inserted will be in (x, N or P)
             */
            if (balance < -1 && parent->right->val < key)
                return _rotateLeft(parent);

            /*
             * @brief case 2.2, the inserted node cause unbalancing for parent `z` places in `Y1` <=> Right Left Side case
                            z --> parent                                                z                                                    x
                           / \                                                         / \                                                  / \
                          M   y                    Right Rotate on node y             M   x                 Left Rotate on node z          z   y
                             / \                  ------------------------------>        / \            ------------------------------>   / \ / \                        
                            x   Y2                                                      N   y                                            M  N P Y2
                           / \                                                             / \              
                          N   P --> the inserted will be in (x, N or P)                   P  Y2             
             */
            if (balance > 1 && parent->left->val > key){
                parent->right = _rotateRight(parent->right);
                return _rotateLeft(parent);
            }   
            
            return parent;
        }

        Node* _remove(Node* parent, IT key) override {
            if (parent == nullptr) return nullptr;
            if (parent->val < key){
                parent->right = _remove(parent->right, key);
            }
            else if (parent->val > key){
                parent->left = _remove(parent->left, key);
            }
            else {
                if (parent->left != nullptr && parent->right != nullptr){
                    Node* successor = this->_minimum(parent->right);
                    parent->val = successor->val;
                    parent->right = _remove(parent->right, successor->val);
                }
                else {
                    if (parent->left == nullptr && parent->right == nullptr)
                        return nullptr;

                    if (parent->left != nullptr)
                        *parent = *parent->left;

                    if (parent->right != nullptr)
                        *parent = *parent->right;                 
                }
            }

            parent->height = 1 + max(_height(parent->left), _height(parent->right));
            int balance = _balance(parent);
            if (balance > 1 && _balance(parent->left) >= 0)
                return _rotateRight(parent);

            if (balance > 1 && _balance(parent->left) < 0){
                parent->left = _rotateLeft(parent->left);
                return _rotateRight(parent);
            }

            if (balance < -1 && _balance(parent->right) <= 0){
                return _rotateLeft(parent);
            }

            if (balance < -1 && _balance(parent->right) > 0){
                parent->right = _rotateRight(parent->right);
                return _rotateLeft(parent);
            }

            return parent;
        }

    public:
        AVLTree() : BinarySearchTree<IT>(){}
        AVLTree(const vector<IT>& arr) : BinarySearchTree<IT>(arr){}
};