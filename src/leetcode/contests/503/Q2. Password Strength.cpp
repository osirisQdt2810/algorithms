#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<int> occurence;
        int point = 0;
        for (auto c : password){
            if (occurence.find(c) == occurence.end()){
                if ('a' <= c && c <= 'z') point += 1;
                if ('A' <= c && c <= 'Z') point += 2;
                if ('0' <= c && c <= '9') point += 3;
                if (c == '!' || c == '@' || c == '#' || c == '$') point += 5;
                occurence.insert(c);
            }
        }
        return point;
    }
};