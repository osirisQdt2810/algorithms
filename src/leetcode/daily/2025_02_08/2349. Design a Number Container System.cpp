#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class NumberContainers {
    public:
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if (m_k2v.find(index) != m_k2v.end()){
                auto old_v = m_k2v[index];
                m_v2ks[old_v].erase(index);
                if (m_v2ks[old_v].empty())
                    m_v2ks.erase(old_v);
            }
            m_k2v[index] = number;
            m_v2ks[number].insert(index);
        }
        
        int find(int number) {
            if (m_v2ks.find(number) == m_v2ks.end()) return -1;
            return *m_v2ks[number].begin();
        }

    private:
        using Key = int;
        using Value = int;
        unordered_map<Value, set<Key>> m_v2ks;
        unordered_map<Key, Value> m_k2v;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    NumberContainers cont;

    cout << cont.find(10) << "\n";   // -1, nothing stored yet
    cont.change(2, 10);
    cont.change(1, 10);
    cont.change(3, 10);
    cont.change(5, 10);
    cout << cont.find(10) << "\n";   // 1, smallest index holding 10
    cont.change(1, 20);
    cout << cont.find(10) << "\n";   // 2, index 1 now holds 20

    return 0;
}