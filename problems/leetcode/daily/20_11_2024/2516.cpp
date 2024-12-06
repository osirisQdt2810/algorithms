#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool existSubArray(string s, int arrLen, int k, int Fa, int Fb, int Fc){
            int N = s.size();
            int currFa = 0, currFb = 0, currFc = 0;
            
            for (int i = 0; i < arrLen; ++i){
                if (s.at(i) == 'a'){
                    ++currFa;
                }
                else if (s.at(i) == 'b'){
                    ++currFb;
                }
                else {
                    ++currFc;
                }
            }

            if (arrLen == 0){
                if (
                    Fa - currFa >= k &&
                    Fb - currFb >= k &&
                    Fc - currFc >= k
                ){
                    return true;
                }
                else {
                    return false;
                }
            }

            
            for (int i = 0; i <= N - arrLen; ++i){
                // cout << "currFa = " << currFa << " - currFb = " << currFb << " - currFc = " << currFc << "\n";
                if (
                    Fa - currFa >= k &&
                    Fb - currFb >= k &&
                    Fc - currFc >= k
                ){
                    return true;
                }

                if (s.at(i) == 'a'){
                    --currFa;
                }
                else if (s.at(i) == 'b'){
                    --currFb;
                }
                else {
                    --currFc;
                }

                if (i < N - arrLen){
                    if (s.at(i + arrLen) == 'a'){
                        ++currFa;
                    }
                    else if (s.at(i + arrLen) == 'b'){
                        ++currFb;
                    }
                    else {
                        ++currFc;
                    }
                }
            }
            return false;
        }

        int takeCharacters(string s, int k) {
            int N = s.size();
            int l = 0, r = N - 3*k, ans = -1;
            int Fa = 0, Fb = 0, Fc = 0;
            for (int i = 0; i < N; ++i){
                if (s.at(i) == 'a'){
                    ++Fa;
                }
                else if (s.at(i) == 'b'){
                    ++Fb;
                }
                else {
                    ++Fc;
                }
            }

            // cout << "Fa = " << Fa << " - Fb = " << Fb << " - Fc = " << Fc << "\n";

            while (l <= r){
                int m = (l + r) / 2;
                if (existSubArray(s, m, k, Fa, Fb, Fc)){
                    ans = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }


            return (ans == -1) ? (-1) : N - ans;
        }
};


int main(){
    Solution sol;

    // string s = "aabaaaacaabc"; int k = 2;
    string s = "caaa"; int k = 1;
    cout << sol.takeCharacters(s, k);
}
