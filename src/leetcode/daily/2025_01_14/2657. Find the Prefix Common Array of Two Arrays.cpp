#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
            int n = A.size();

            unordered_set<int> res;
            vector<int> target, Acurr, Bcurr;
            target.reserve(n);
            Acurr.reserve(n);
            Bcurr.reserve(n);

            for (int i = 0; i < n; ++i){
                int a = A[i], b = B[i];
                Acurr.push_back(a);
                Bcurr.push_back(b);                
                if (res.find(a) == res.end()){
                    if (std::find(Bcurr.begin(), Bcurr.end(), a) != Bcurr.end()){
                        res.insert(a);
                    }
                }

                if (res.find(b) == res.end()){
                    if (std::find(Acurr.begin(), Acurr.end(), b) != Acurr.end()){
                        res.insert(b);
                    }
                }

                target.push_back(res.size());
            }
            return target;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();