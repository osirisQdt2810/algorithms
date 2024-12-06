#include <bits/stdc++.h>

using namespace std;

/**
    1574. Shortest Subarray to be Removed to Make Array Sorted

    Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

    Return the length of the shortest subarray to remove.

    A subarray is a contiguous subsequence of the array.
**/

class Solution {
public:
    /**
     * Ý tưởng:
        - Mảng array có thể chia thành 2 phần: 
                a1 a2 a3... aN > b1 <= b2 <= ... <= bM
                0  0  0 ... 0    1     1     ...    1
        - Như vậy, ta xét i chạy từ 1->N. Ta mong muốn Giữ nguyên mảng từ a1->ai, cần xóa subarray 
          ngắn nhất từ a[i+1]->... sao cho được dãy không giảm.
        - Điều này tương đương với, với mỗi i, ta tìm j thuộc từ 1->M sao cho:
                a[i] <= b[j] <= b[j+1] <=... <= bM
        - Tại sao vậy? Bởi vì nếu điểm cắt cuối không thuộc mảng b, mà vẫn thuộc mảng a, thì dãy còn 	 lại chắc chắn ko phải dãy không giảm (vì có aN > b1).
     */
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        int le = 0;              while (le + 1 < arr.size() && arr[le] <= arr[le + 1]) le++;
        if (le == arr.size() - 1) return 0;
        
        int rs = arr.size() - 1; while (rs - 1 >= 0 && rs > le && arr[rs - 1] <= arr[rs]) rs--;

        int res = rs; // when i = -1
        // cout << "le = " << le << " - rs = " << rs << "\n";
        for (int i = 0; i <= le; ++i){
            int l = rs, r = arr.size() - 1, j = arr.size();
            while (l <= r){
                int m = (l + r) / 2;
                if (arr[i] <= arr[m]){
                    j = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            // cout << "arr[" << i << "] = " << arr[i] << " -> arr[" << j << "] = " << arr[j] << "\n";
            res = min(res, j - i - 1);

        }
        return res;
    }
};

int main(){
    // vector<int> arr = {1, 2, 3, 4, 5};

    // vector<int> arr = {1, 1, 1};

    vector<int> arr = {1,2,3,10,4,2,3,5};

    Solution s;
    cout << s.findLengthOfShortestSubarray(arr);
}
