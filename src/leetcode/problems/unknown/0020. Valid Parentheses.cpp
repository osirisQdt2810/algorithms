#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        bool validOpenCloseChars(char& c, char& t){
            return (
                (c == '[' && t == ']') ||
                (c == '(' && t == ')') ||
                (c == '{' && t == '}')
            );
        }

    public:
        bool isValid(string s) {
            stack<char> st;

            for (auto& c : s){
                if (c == '[' || c == '(' || c == '{'){
                    st.push(c);
                } 
                else {
                    if (st.empty()) return false;
                    char t = st.top(); st.pop();
                    if (!validOpenCloseChars(t, c)) return false;
                }
            }

            return st.empty();
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){

    return 0;
}