#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
    private:
        int lastZeroPosDis = -1;

        int productOfNumbers = 1;
        vector<int> prods;

    public:
        ProductOfNumbers() {
            prods.push_back(1);
        }
        
        void add(int num) {
            if (num == 0){
                lastZeroPosDis = 0;
                productOfNumbers = 1;
                prods.clear();
                prods.push_back(1);
            }
            else {
                if (lastZeroPosDis != -1){
                    ++lastZeroPosDis;
                }

                productOfNumbers *= num;
                prods.push_back(productOfNumbers);
            }
            // cout << "num = " << num << " -> lastZeroPosDis = " << lastZeroPosDis << "\n";
        }
        
        int getProduct(int k) {
            // cout << "k = " << k << " -> lastZeroPosDis = " << lastZeroPosDis << "\n";
            if (lastZeroPosDis != -1 && lastZeroPosDis <= k - 1) return 0;
            int currSize = prods.size();
            int j = currSize - 1;
            int i = max(1, currSize - k) - 1;
            return prods[j] / prods[i];
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */
int main(){
    ProductOfNumbers* obj = new ProductOfNumbers();
    obj->add(3);        // [3]
    obj->add(0);        // [3,0]
    obj->add(2);        // [3,0,2]
    obj->add(5);        // [3,0,2,5]
    obj->add(4);        // [3,0,2,5,4]
    cout << obj->getProduct(2) << "\n\n"; // return 20. The product of the last 2 numbers is 5 * 4 = 20
    cout << obj->getProduct(3) << "\n\n"; // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    cout << obj->getProduct(4) << "\n\n"; // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    obj->add(8);        // [3,0,2,5,4,8]
    cout << obj->getProduct(2) << "\n\n"; // return 32. The 

    return 0;
}