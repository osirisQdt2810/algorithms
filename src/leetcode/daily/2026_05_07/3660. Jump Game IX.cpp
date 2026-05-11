#include <vector>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
class Solution {
    private:
        void dac(const vector<int>& nums, vector<int>& ans, vector<int>& prefix_argmax, int r, int currMax, int rightMin){
            int imax = prefix_argmax[r];
            if (nums[imax] <= rightMin) currMax = nums[imax];
            for (int j = r; j >= imax; --j){
                rightMin = min(rightMin, nums[j]);
                ans[j] = currMax;
            }
            if (imax == 0) return;
            return dac(nums, ans, prefix_argmax, imax - 1, currMax, rightMin);
        }

        struct Item {
            int value;
            int left, right;
        };

    public:
        vector<int> maxValueDAC(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n);
            // we split the array [0 1 ... imax ... n - 1] into two parts:
            // [0, imax-1] imax [imax + 1, n-1] => ans[j] = nums[imax] for all j >= imax
            // call imax2 is the arg-max of [0, imax-1], so we have 4 parts:
            // [0, imax2-1] imax2 [imax2 + 1, imax-1] imax [imax+1, n-1]
            // L1           imax2        L2           imax      L3
            // we have two observations:
            //      1. if nums[imax2] > min(L3)     => for all j in [imax2 -> n-1], ans[j] = nums[imax]
            //      2. if nums[imax2] <= min(L3)    => for all j in [imax2 -> imax-1], ans[j] = nums[imax2]
            // we just need to deal with L1:
            //      3. With L1, we see a similar pattern/approach to L2 and [imax, L3]. In detail, it is L1 and [imax2, L2] => do the recursion
            // Looking more closely, we can see the DAC pattern: 
            // [left-part] imax [right-part]
            // if nums[imax] <= min(right of right-part) => [right-part] is separated from [curr_max [right-right-part]]
            //          => `curr_max` will be imax    
            //          && ans[right-part] = imax
            //          && min(right of right-part) = min(right-part)
            // if nums[imax] >  min(right of right-part) => we just merge [right-part] into [curr_max [right-right-part]] as [right-right-part] of the next recursion
            //          && `curr_max` remains the same
            //          && ans[right-part] = curr_max
            //          && min(right of right-part) = min(right-part, right-right-part)
            vector<int> prefix_argmax(n, -1); int max_num = -1e9, argmax = -1;
            for (int i = 0; i < n; ++i){
                if (max_num <= nums[i]){
                    max_num = nums[i];
                    argmax = i;
                }
                prefix_argmax[i] = argmax;
            }
            dac(nums, ans, prefix_argmax, n-1, -1e9, 1e9);
            return ans;
        }
        
        vector<int> maxValueMonolithStack(vector<int>& nums) {
            int n = nums.size();
            stack<Item> mono_stack;

            for (int i = 0; i < n; ++i){
                // try to merge i with previous connected components:
                Item item = {nums[i], i, i};

                // find the last component T where max(component) = component.value <= item.value
                // all the other components on the path of T -> i will have max(component) > item.value
                // thus, item can be merged into those components.
                // note: we will have X Tj ... Tk item
                // with X.value <= item.value and item.value < Tj.value < ... < Tk.value
                // => item will be merged with Tk, Tk-1... Tj, they will create a new component T
                // 2 1 4 3 8 6 9 7 -> (2) 4 3 8 6 9 7 -> (2) (4) 8 6 9 7 -> (2) (4) (8) 9 7 -> (2) (4) (8) (9) 7 -> (2) (4) (9)
                while (!mono_stack.empty() && mono_stack.top().value > nums[i]){
                    // merge Item into component `top`
                    Item top = mono_stack.top(); mono_stack.pop();
                    item.left = top.left;
                    item.value = max(item.value, top.value);
                }
                // cout << item.left << " " << item.right << " " << item.value << "\n";
                mono_stack.push(item);
            }

            vector<int> ans(n);
            while (!mono_stack.empty()){
                auto& item = mono_stack.top(); mono_stack.pop();
                for (int i = item.left; i <= item.right; ++i)
                    ans[i] = item.value;
            }
            return ans;
        }

        vector<int> maxValue(vector<int>& nums) {
            return maxValueMonolithStack(nums);
        }

};

int main(){
    Solution sol;

    vector<int> nums = {2, 3, 1};
    for (auto val : sol.maxValue(nums)) {
        cout << val << " ";
    }

    return 0;
}