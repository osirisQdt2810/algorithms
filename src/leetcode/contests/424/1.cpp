#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countValidSelections(vector<int>& nums) {
            vector<int> positions;
            for (int i = 0; i < nums.size(); ++i){
                if (nums[i] == 0){
                    positions.push_back(i);
                }
            }
            // cout << "here\n";
            int validSolutions = 0;
            for (int pos : positions){
                for (int d = -1; d <= 1; d +=2 ){

                    int currPos = pos;
                    int currDirection = d;
                    vector<int> currNums = nums;

                    while (currPos >= 0 && currPos < currNums.size()){
                        if (currNums[currPos] == 0){
                            currPos += currDirection;
                        }

                        else if (currNums[currPos] > 0){
                            --currNums[currPos];
                            currDirection = -currDirection;
                            currPos += currDirection;
                        }
                    }

                    
                    int numZeros = 0;
                    for (auto& num : currNums){
                        numZeros += (num == 0);
                    }
                    // cout << "pos_zero = " << pos << " direction: " << ((d == -1) ? "left" : "right") << " -> num_zeros = " << numZeros << "\n";
                    if (numZeros == currNums.size()){
                        ++validSolutions;
                    }
                }
            }
            return validSolutions;
        }
};