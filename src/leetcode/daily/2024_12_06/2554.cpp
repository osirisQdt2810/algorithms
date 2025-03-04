#include <bits/stdc++.h>

using namespace std;

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
        int height;
        BTreeNode<IT> *left;
        BTreeNode<IT> *right;
        BTreeNode() : val(0),  height(1), left(nullptr), right(nullptr) {}
        BTreeNode(IT x) : val(x),  height(1), left(nullptr), right(nullptr) {}
        BTreeNode(IT x, BTreeNode<IT> *left, BTreeNode<IT> *right) : val(x),  height(1), left(left), right(right) {}

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

template<typename IT>
class Tree {
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
        using Node = BTreeNode<IT>;
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

class Solution {
public:
    int maxCount2(vector<int>& banned, int n, int maxSum) {
        banned.push_back(0);
        banned.push_back(n + 1);
        sort(banned.begin(), banned.end());
        int counter = 0;
        for (int i = 1; i < banned.size(); ++i){
            int curr = banned[i];
            int prev = banned[i - 1];
            if (prev >= n){
                break;
            }
            int numb = prev + 1;
            // cout << "prev = " << prev << " -> curr = " << curr <<  "\n";
            while (maxSum >= numb && numb < curr && numb <= n){
                maxSum -= numb;
                cout << "   -> choose: " << numb << " --- maxSum = " << maxSum << "\n";
                ++counter;
                ++numb;
            }
            // cout << "maxSum = " << maxSum << " - counter = " << counter << "\n";
        }

        return counter;
    }

    int maxCount(vector<int>& banned, int n, int maxSum) {
        // BinarySearchTree<int> set(banned);
        AVLTree<int> set(banned);
        int counter = 0;
        for (int i = 1; i <= n; ++i){
            if (set.find(i)) continue;
            if (maxSum < i) break;

            maxSum -= i;
            ++counter;
        }
        return counter;
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

    // vector<int> banned = {1,6,5};
    // int n = 5, maxSum = 6;

    // vector<int> banned = {11};
    // int n = 7, maxSum = 50;

    vector<int> banned = {179,266,77,196,59,313,286,41,21,201,57,237,74,333,101,281,227,25,138,10,304,55,50,72,244,113,159,330,154,156,311,170,283,9,224,46,197,2,325,237,54,168,275,166,236,30,250,48,274,331,240,153,312,63,303,342,79,37,165,20,79,293,103,152,215,44,56,196,29,251,264,210,212,135,296,123,289,257,208,309,67,114,170,119,337,163,242,162,109,318,51,105,272,240,107,226,224,188,224,317,27,102,63,128,3,133,27,134,186,220,198,24,274,287,267,8,13,322,278,166,304,165,342,89,184,300,312,339,163,307,123,137,293,227,229,57,66,13,71,233,260,79,228,301,4,4,89,196,193,337,205,51,144,99,104,73,10,311,240,168,77,244,114,217,186,134,229,241,46,89,54,127};
    int n = 4085, maxSum = 109718563;

    // vector<int> banned = {1249,641,3360,2977,1652,982,911,87,311,899,97,662,3112,2047,3025,3423,2086,2300,2799,3107,971,2695,2604,1838,783,2410,2525,2855,519,274,268,1703,111,2319,1761,2216,2923,342,418,3124,1885,999,1427,2426,3351,2789,3164,3370,3495,3078,1753,20,2121,423,771,2770,2812,17,327,1448,1563,2752,2614,417,1685,1096,2109,1784,2653,1544,3150,2933,816,1024,2613,417,13,931,3568,132,2481,3017,3443,152,2226,658,3220,2394,279,3062,2613,1006,36,1724,3233,2577,514,2311,3167,3369,789,1432,1062,2653,2194,2003,1647,3068,89,702,2930,3422,214,940,3377,3202,2200,883,3276,3544,2236,2896,2435,3236,2674,3484,3556,3122,1999,3307,3326,484,803,238,3247,1589,1159,3624,1875,1265,1535,591,1959,253,1707,3209,271,3190,529,2784,2814,1153,3123,240,18,2008,2689,124,2094,871,2925,1128,935,1445,1287,2404,2391,3371,1481,2407,1733,2744,3026,3017,3019,244,2489,2822,39,1207,630,2681,922,800,245,2552,1462,3411,1201,627,2135,1649,1463,3527,2694,738,2437,269,1479,3604,3097,1139,2686,648,240,2938,2665,2218,2017,3170,2765,581,1559,1153,1609,2520,2385,2778,535,185,2569,3307,1217,1436,774,1046,2692,3127,811,2716,1999,1445,640,2827,3106,2160,1805,1863,2402,262,670,2174,1793,2888,3189,3625,2892,2798,2706,3498,3082,1071,1946,554,2249,1208,1004,2977,907,2747,371,2060,3064,2610,1945,2798,3429,2452,902,1975,2647,2520,994,3379,1138,3576,2859,2024,927,3387,2696,890,2751,2645,3337,1740,125,2842,1725,1114,1740,2499,1867,769,3014,3376,323,1290,3417,2747,129,1015,143,1836,1718,1383,1533,885,3475,2907,3347,2546,1872,33,2426,1710,2012,2720,3071,3212,3096,30,2870,3422,905,2990,2995,1548,421,372,1717,604,839,2091,1290,536,1120,1400,2708,868,3376,1082,808,2776,438,2406,1130,1036,992,3217,284,925,604,1648,3621,3555,1497,1121,2931,435,2904,1359,3439,2202,1696,2811,3533,2105,1120,2022,2382,1946,2696,129,1311,1980,3532,771,2870,2359,2111,121,283,2983,1642,2410,1738,154,2302,1453,3475,2012,3539,3316,951,1905,3014,1790,477,3294,3457,3311,2867,622,574,3179,2212,2415,111,800,950,821,2678,1338,1703,1730,3603,2280,2494,3094,3549,1364,32,1017,2571,2893,1376,3483,2758,1800,503,2936,954,153,2593,2137,195,635,1904,3431,2008,1087,902,1893,1955,2779,713,2693,57,2424,2493,3346,2212,2685,2182,1556,679,1046,1950,473,2817,1538,2775,1513,1826,698,1923,1665,2579,207,512,1137,71,191,3185,2801,2860,548,295,2484,2581,2522,1232,1758,1231,1837,3362,1493,686,2818,370,2947,3060,288,3596,3623,1509,491,872,2961,2160,3632,754,3232,1752,194,1249,1020,3171,363,2382,3117,1641,294,3238,1846,3622,3237,3502,1880,2699,1432,2346,1173,1700,1566,2000,409,2503,2575,1928,866,1137,987,1156,1764,451,2566,635,1551,243,2913,1925,500,412,674,447,3264,1492,3362,2901,965,3370,2688,2553,2609,492,1801,3068,3108,3255,3480,3520,1808,780,1341,3520,1603,2415,2973,1449,2496,1345,3139,413,1326,1018,2533,3397,3036,2081,2395,3223,1946,1185,949,114,221,1809,3586,2607,2507,624,1393,871,3355,283,2540,505,2883,2325,2161,399,3598,783,1439,2593,620,2161,1326,4,3299,1273,3017,2799,1895,441,1924,543,3574,271,1244,3041,3506,2683,2550,2725,816,1846,2880,2537,314,704,1306,294,2436,499,1201,1142,3044,2737,2869,2889,3633,1365,1637,615,222,238,1688,3632,90,1659,3315,2696,2719,2385,2514,2962,252,2277,3332,787,553,1727,1061,1408,2451,564,257,2783,2682,1849,2896,259,1274,763,1098,1506,1356,2020,1673,2794,2782,333,2084,1362,657,233,1393,1660,1792,129,3271,2505,3104,3262,838,1752,3522,1604,2936,670,3570,2504,2609,3493,136,1997,473,1956,1757,1713,676,2618,3556,1645,1881,17,1345,934,856,1563,2833,1606,2993,3209,3526,1197,1835,144,2230,1582,2389,242,3629,3032,2935,1768,3443,3397,434,1250,1570,685,1312,1548,965,2978,345,2112,2222,3152,412,2091,2440,2648,3282,3224,2424,667,1498,2887,3,1278,1439,3096,1292,3069,3044,2140,111,3020,362,397,388,3574,1403,2327,3585,19,1776,2276,1474,3174,2501,595,2820,3626,351,3373,106,3141,1549,296,1762,3181,454,995,2253,597,641,1870,981,3145,2733,1243,45,2329,2696,3141,1137,565,202,104,2446,1876,3570,103,33,790,2060,1340,2998,1553,2767,2515,360,343,1889,20,3069,1571,1341,462,1484,3167,1648,491,338,1873,2635,3057,3412,1881,3496,2122,2033,1183,920,2185,2320,3508,2720,1676,861,738,439,1506,380,1671,2250,2322,1654,506,1599,1038,1229,2989,2787,3048,2006,2582,2366,3020,1338,2818,778,3547,2415,894,3419,2873,1851,2434,1530,2854,475,3131,2161,386,211,2520,1559,228,1444,1925,927,2871,3175,2947,1108,3463,1027,584,1362,1576,3121,480,1270,2389,193,3368,3490,589,1301,794,756,1346,2338,1246,3077,2557,3610,1190,2285,206,1493,285,114,442,2797,1678,1679,1069,1662,256,368,2599,3092,804,2642,871,2361,2590,2900,2748,1913,2566,2287,3431,871,1442,548,1256,2970,2724,3350,350,3097,3004,2258,940,1763,550,1171,1966,1694,374,1919,2482,532,1716,830,707,2399,279,1332,288,2357,2410,2567,2195,2433,3471,2361,2672,1684,2291,1896,697,2208,353,1423,3087,3192,3111,506,3601,3159,1993,2826,3575,2546,1953,808,425,518,292,1640,1215,1560,2064,2469,1350,2079,149,2239,2370,3540,665,244,456,3410,2623,1501,1931,2966,873,2214,1191,2555,3158,1394,672,1271,1822,2854,2687,2595,1310,635,2982,2094,705,1518,2883,3149,1336,7,437,1851,1404,1279,2781,3625,3120,2896,1805,1820,900,1884,105,3526,1683,1823,2344,1241,3247,2942,3187,1539,2656,1275,328,3374,2426,3336,2265,1220,1027,2814,354,918,3034,3455,3509,2110,650,3525,2872,708,1637,2427,3441,3202,2708,2949,331,1453,694,1693,2354,2982,3319,1915,2548,259,2434,1382,2519,3262,174,3318,373,1791,3312,2253,3348,2121,315,2703,1728,526,8,146,713,1604,3489,681,452,2096,2671,1991,75,3592,3196,3276,407,3448,99,454,1726,562,2924,1733,537,969,457,835,3177,737,1289,1664,1805,1752,968,555,3216,2428,1961,954,2738,3285,194,2714,1345,2244,208,2320,1221,1013,2895,1417,2849,2401,3017,2022,1275,3393,3029,2498,609,732,2679,3227,1023,825,299,871,732,954,3019,2678,2382,74,382,1396,2822,3496,1003,252,2613,586,3121,1385,991,1372,3456,3100,3347,3402,794,1590,805,2971,1701,3352,1170,3013,3588,3185,2674,1006,2662,2384,3482,2679,2539,2332,2310,2815,301,1050,1527,3069,1438,2815,33,3488,1173,2393,2738,1340,2457,2796,2947,3540,313,1249,2227,2276,3440,3085,885,3607,2451,2881,2807,3098,1753,138,358,931,3435,2485,3621,268,3414,835,128,1355,3593,429,1990,3362,1134,2748,2765,2542,3523,427,3396,12,3055,2960,954,2729,340,298,1629,1260,3627,2341,2600,2343,1432,1576,2609,3015,3147,3322,1101,3060,539,2273,1206,1314,2334,1809,3154,1471,1225,131,2373,1015,3309,3270,3080,1910,2073,2790,617,3083,2066,496,835,246,2728,2555,2142,3562,2081,761,3450,2777,731,2698,1289,2262,3055,1152,1289,1067,695,1942,3255,1212,974,1295,839,2274,722,1858,2546,3559,258,2867,1948,1900,1082,3527,3517,76,601,3340,925,533,2226,2281,1620,1854,711,2922,2429,239,295,510,2498,1706,669,1694,1506,3239,2688,67,2101,1239,108,2586,1456,1153,2642,2460,1579,88,700,1331,59,2020,1924,3462,1160,3593,1191,1438,1338,561,794,979,1065,1914,3225,3238,2298,3630,2126,164,3497,3377,3403,3317,2108,2208,3085,2618,1720,2189,2650,1324,163,1840,1748,3441,2987,2389,1532,2353,1561,1850,862,1404,2310,2560,660,564,1261,2706,2296,3035,219,3117,2882,3130,15,779,979,433,865,1303,1243,1252,1387,1908,1926,191,2034,1558,2031,2152,977,3399,2992,2626,1597,547,2508,3403,273,2771,638,316,3150,136,1380,1587,2684,1239,2665,2366,779,410,28,1493,2742,1268,3389,2228,364,3139,1878,1121,2030,2679,1794,2161,163,2917,2200,469,443,3200,20,2320,3074,614,907,1030,2350,2525,2833,1479,3324,1831,1444,1390,1603,102,1986,902,3330,548,2028,509,1560,1370,1136,2523,125,2032,1923,858,530,879,711,655,1314,714,2593,3348,2354,2395,3605,1564,1925,938,533,1072,702,2111,1931,3222,987,3473,3324,2997,469,786,821,715,3245,1961,2237,3393,465,2590,3428,2711,1364,2380,1428,1353,1107,3018,3420,1443,3404,174,3398,1562,1707,699,2134,2577,251,1782,2074,3075,1894,1472,1748,721,1864,3495,239,2706,3460,756,2819,3141,3379,3351,1572,3197,2170,174,2630,1504,1260,1322,20,2746,2709,1958,2944,1727,2189,593,1284,2561,3189,2447,310,607,2396,1184,641,394,851,599,3610,1114,2800,755,3256,1504,1884,265,915,514,545,1800,2959,694,2996,3083,645,2000,171,2944,1352,1523,1361,1930,997,1530,1288,2045,666,659,1515,2140,573,2998,3312,2851,1759,1593,732,753,2592,1361,609,2212,2723,2195,202,3340,3255,1446,1060,3506,2623,213,3120,2141,1891,1340,1324,1187,3025,3295,762,1888,2067,8,2251,2948,2161,1270,2847,2310,1052,2915,3248,1432,2699,2871,2214,2976,173,2981,158,1958,3187,1644,2910,1565,1304,2405,2803,3125,2040,1298,2137,3611,2520,8,163,2029,146,3007,2159,3211,836,193,2638,2924,362,3488,2225,2493,3558,3506,727,211,602,3206,32,3293,2236,1275,2404,818,2373,3392,3296,2776,3341,2038,3101,3091,2563,3108,1878,3284,717,2167,2649,1625,3296,441,3415,936,1807,3256,458,298,1124,2565,3609,2395,2680,1530,909,3094,1214,483,75,2221,3249,1394,2752,2402,1534,3151,241,475,2525,2576,819,446,217,3191,2785,671,1680};
    // int n = 5080, maxSum = 14;

    cout << sol.maxCount(banned, n, maxSum);

    return 0;
}