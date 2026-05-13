#include <vector>
#include <iostream>
#include <string>
#include <cassert>
#include <map>

using namespace std;

// You are given an array tasks where tasks[i] = [actuali, minimumi]:

// actuali is the actual amount of energy you spend to finish the ith task.
// minimumi is the minimum amount of energy you require to begin the ith task.
// For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

// You can finish the tasks in any order you like.

// Return the minimum initial amount of energy you will need to finish all the tasks.

 

// Example 1:

// Input: tasks = [[1,2],[2,4],[4,8]]
// Output: 8
// Explanation:
// Starting with 8 energy, we finish the tasks in the following order:
//     - 3rd task. Now energy = 8 - 4 = 4.
//     - 2nd task. Now energy = 4 - 2 = 2.
//     - 1st task. Now energy = 2 - 1 = 1.
// Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.
// Example 2:

// Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
// Output: 32
// Explanation:
// Starting with 32 energy, we finish the tasks in the following order:
//     - 1st task. Now energy = 32 - 1 = 31.
//     - 2nd task. Now energy = 31 - 2 = 29.
//     - 3rd task. Now energy = 29 - 10 = 19.
//     - 4th task. Now energy = 19 - 10 = 9.
//     - 5th task. Now energy = 9 - 8 = 1.
// Example 3:

// Input: tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
// Output: 27
// Explanation:
// Starting with 27 energy, we finish the tasks in the following order:
//     - 5th task. Now energy = 27 - 5 = 22.
//     - 2nd task. Now energy = 22 - 2 = 20.
//     - 3rd task. Now energy = 20 - 3 = 17.
//     - 1st task. Now energy = 17 - 1 = 16.
//     - 4th task. Now energy = 16 - 4 = 12.
//     - 6th task. Now energy = 12 - 6 = 6.

class Solution {
    public:
        int minimumEffort(vector<vector<int>>& tasks) {
            // it is really hard greedy problem.
            // let's say in easy case, we have 2 tasks:
            //    task 1: [a, b]
            //    task 2: [c, d]
            // Call X is the minimum energy we need to have to accomplish these two tasks.
            // Thus:
            //  - if doing task 1 -> 2, we need:
            //      - X >= b
            //      - X - a >= d
            //      - X - a - c >= 0 (obviously if X - a >= d)
            //      => X >= max(b, a + d)
            //  - if doing task 2 -> 1, we need:
            //      - X >= d
            //      - X - c >= b
            //     => X >= max(d, b + c)
            //  - case 1: b >= a + d => b - a >= d => we choose task 1: X = b (because if we choose task 2 => X >= b + c > b)
            //  - case 2: d >= b + c => d - c >= b => we choose task 2: X = d (because if we choose task 1 => X >= a + d > d)
            //  - case 3: a + d >= b && b + c >= d => we choose task based-on: a + d >=< b + c <=> b - a >=< d - c.
            //      - 3.1. b - a >= d - c => if we choose task 1->2: X >= a + d, task 2->1: X >= b + c > a + d => we should choose task 1
            //      - 3.2. d - c >= b - a => if we choose task 2->1: X >= b + c, task 1->2: X >= a + d > b + c => we should choose task 2
            // Overall:
            //      - if: b - a >= d - c => choose task 1
            //      - if: d - c >= b - a => choose task 2
            // meaning:
            //      - A task with a larger (minimum - actual) requires a high starting energy but consumes relatively little energy, so delaying it wastes more initial energy and should therefore be done earlier.
            // Therefore, the problem is easier to solve:
            //      - sort: [a1, b1], [a2, b2]... [an, bn], where bi-ai >= bj-aj for all (i < j)
            //      - the target is: X = max(a1+...+a{i}+b{i+1}) for all i->n-1
            int n = tasks.size();
            sort(tasks.begin(), tasks.end(), [](const vector<int>& lhs, const vector<int>& rhs){ return lhs[1] - lhs[0] > rhs[1] - rhs[0]; });
            int sum = 0, ans = tasks[0][1];
            for (int i = 0; i + 1 < n; ++i){
                sum += tasks[i][0];
                ans = max(ans, sum + tasks[i+1][1]);
            }
            return ans;
        }
};
int main(){
    Solution sol;

    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};
    cout << sol.minimumEffort(tasks);
    return 0;
}