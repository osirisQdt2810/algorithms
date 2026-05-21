#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // O(nlogn)
    vector<int> findThePrefixCommonArrayHashSet(vector<int>& A, vector<int>& B) {
        unordered_set<int> common;
        int n = A.size();
        vector<int> res(n);
        res[0] = (A[0] == B[0]);
        common.insert(A[0]);
        common.insert(B[0]);
        for (int i = 1; i < n; ++i){
            if (A[i] == B[i]){
                res[i] = res[i-1] + 1;
                common.insert(A[i]);
                continue;
            }
            bool ai_existed = common.find(A[i]) != common.end();
            bool bi_existed = common.find(B[i]) != common.end();
            res[i] = res[i-1] + ai_existed + bi_existed;
            if (!ai_existed) common.insert(A[i]);
            if (!bi_existed) common.insert(B[i]);
        }
        return res;
    }

    // O(n)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        vector<int> freq(n+1);
        res[0] = (A[0] == B[0]);
        freq[A[0]] = 1;
        freq[B[0]] = 1;
        for (int i = 1; i < n; ++i){
            if (A[i] == B[i]){
                res[i] = res[i-1] + 1;
                freq[A[i]] = 1;
                continue;
            }
            res[i] = res[i-1] + (freq[A[i]] == 1) + (freq[B[i]] == 1);
            freq[A[i]] = 1;
            freq[B[i]] = 1;
        }
        return res;
    }
};