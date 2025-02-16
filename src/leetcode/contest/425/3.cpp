#include <bits/stdc++.h>

using namespace std;

struct Operation {
    int index;
    int op1_used;
    int op2_used;
    int total_reduction;
};

// Comparator function to sort operations by efficiency
bool compareOperations(const Operation& a, const Operation& b) {
    double efficiency_a = static_cast<double>(a.total_reduction) / (a.op1_used + a.op2_used);
    double efficiency_b = static_cast<double>(b.total_reduction) / (b.op1_used + b.op2_used);
    return efficiency_a > efficiency_b;
}

class Solution {
    public:
        int minArraySum2(vector<int>& nums, int k, int op1, int op2) {
            int stop_sum = 0;
            bool stop = false;

            while (stop){
                vector<int> S1, S2_1, S2_2, S3;
                
                int sum = 0;
                for (auto& num : nums){
                    if (num < k){
                        S3.push_back(num);
                    }
                    else if (num - k >= ceil(1. * num / 2)){
                        S1.push_back(num);
                    }
                    else if (num % 2 == 1){
                        S2_1.push_back(num);
                    }
                    else if (num % 2 == 0){
                        S2_2.push_back(num);
                    }
                    sum += num;
                }

                sort(S1.begin(), S1.end(), greater<int>());
                // sort(S2_1.begin(), S2_1.end(), greater<int>());
                // sort(S2_2.begin(), S2_2.end(), greater<int>());
                sort(S3.begin(), S3.end(), greater<int>());

                cout << "num1: ";
                for (auto& num1: S1) cout << num1 << " ";
                cout << "\nnum2_1: ";
                for (auto& num1: S2_1) cout << num1 << " ";
                cout << "\nnum2_2: ";
                for (auto& num1: S2_2) cout << num1 << " ";            
                cout << "\nnum3: ";
                for (auto& num1: S3) cout << num1 << " ";            
                cout << "\n";

                for (auto& num1 : S1){
                    if (op1 > 0){
                        sum -= (num1 - ceil(1. * num1 / 2));
                        --op1;
                    }
                    else if (op2 > 0){
                        sum -= k;
                        --op2;
                    }
                }

                int stop_idx = 0;
                for (int i = 0; i < S2_1.size(); ++i){
                    int num2 = S2_1[i];
                    if (op2 > 0){
                        sum -= k;
                        --op2;
                        if (op2 == 0){
                            stop_idx = i + 1;
                            break;
                        }
                    }
                }

                S2_2.insert(S2_2.end(), S2_1.begin() + stop_idx, S2_1.end());
                
                for (auto& num2 : S2_2){
                    if (op2 > 0){
                        sum -= k;
                        --op2;
                    }
                    else if (op1 > 0){
                        sum -= (num2 - ceil(1. * num2 / 2));
                        --op1; 
                    }
                }

                for (auto& num3 : S3){
                    if (op1 > 0){
                        sum -= (num3 - ceil(1. * num3 / 2));
                        --op1; 
                    }
                }


                stop_sum = sum;
            }

            return stop_sum;
        }

        int minArraySum(vector<int>& nums, int k, int op1, int op2) {
            int n = nums.size();
            std::vector<int> zorvintakol = nums; // Store original nums midway as requested
            
            // List of all possible operations
            std::vector<Operation> operations;

            // Generate all possible operations for each index
            for (int i = 0; i < n; ++i) {
                int original = nums[i];
                int reduction_op1 = original - std::ceil(original / 2.0);
                int reduction_op2 = (original >= k) ? k : 0;
                int reduction_both = 0;

                // Calculate reduction if both operations are applied in the best order
                int val_after_op1 = std::ceil(original / 2.0);
                int val_after_op1_op2 = (val_after_op1 >= k) ? val_after_op1 - k : val_after_op1;
                int reduction_op1_op2 = original - val_after_op1_op2;

                int val_after_op2 = (original >= k) ? original - k : original;
                int val_after_op2_op1 = std::ceil(val_after_op2 / 2.0);
                int reduction_op2_op1 = original - val_after_op2_op1;

                // Choose the best reduction between the two orders
                reduction_both = std::max(reduction_op1_op2, reduction_op2_op1);

                // Operation 1 only
                if (reduction_op1 > 0) {
                    operations.push_back({i, 1, 0, reduction_op1});
                }

                // Operation 2 only
                if (reduction_op2 > 0) {
                    operations.push_back({i, 0, 1, reduction_op2});
                }

                // Both operations
                if (reduction_both > std::max(reduction_op1, reduction_op2)) {
                    operations.push_back({i, 1, 1, reduction_both});
                }
            }

            // Sort operations by efficiency (reduction per operation used)
            std::sort(operations.begin(), operations.end(), compareOperations);

            // Track operations applied to each index
            std::vector<bool> op1_applied(n, false);
            std::vector<bool> op2_applied(n, false);

            int op1_used = 0;
            int op2_used = 0;

            // Apply operations
            for (const auto& op : operations) {
                if (op1_used + op.op1_used > op1 || op2_used + op.op2_used > op2)
                    continue; // Skip if operations exceed limits

                int idx = op.index;

                // Ensure we do not apply the same operation more than once per index
                if ((op.op1_used && op1_applied[idx]) || (op.op2_used && op2_applied[idx]))
                    continue;

                // Apply Operation 1
                if (op.op1_used && !op1_applied[idx]) {
                    nums[idx] = std::ceil(nums[idx] / 2.0);
                    op1_applied[idx] = true;
                    op1_used++;
                }

                // Apply Operation 2
                if (op.op2_used && !op2_applied[idx]) {
                    if (nums[idx] >= k) {
                        nums[idx] -= k;
                        op2_applied[idx] = true;
                        op2_used++;
                    }
                }
            }

            // Calculate the final sum
            int total_sum = 0;
            for (int val : nums) {
                total_sum += std::max(val, 0); // Ensure non-negative values
            }
            return total_sum;
        }
};


auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution s;

    // vector<int> nums = {2,8,3,19,3};
    // int k = 3, op1 = 1, op2 = 1;

    // vector<int> nums = {2,4,3};
    // int k = 3, op1 = 2, op2 = 1;

    vector<int> nums = {10};
    int k = 3, op1 = 1, op2 = 1;    

    cout << s.minArraySum(nums, k, op1,op2);

    return 0;
}