#include <bits/stdc++.h>

using namespace std;

/**
    862. Shortest Subarray with Sum at Least K

    Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

    A subarray is a contiguous part of an array.
**/

/**
 * @brief Ý tưởng: Bài toán về cơ bản sẽ đưa về được dạng bài, cho 1 mảng s1, s2...sN. 
 *        Cần tìm (i < j) sao cho (j - i) nhỏ nhất mà s[j] - s[i] >= k.
 *          +) s ở đây chính là các prefix sum: s[i] = a[1] + a[2] + ... + a[i]
 * Bài toán dễ hơn: 
 *          +) Nếu mảng ban đầu a chứa toàn số không âm a[i] >= 0 => mảng prefix sum s tăng dần
 *              => Ta có thể sử dụng binary_search: Với mỗi i (s[i]) cần tìm s[j] >= s[i] + k, với j chạy từ i+1->N, trong đó đã có điều kiện BS: s[1] <= s[2] <= ... <= s[N]
 * Nhưng bài toán ở đây mảng ban đầu a bất kì (có thể âm hoặc dương) => s không tăng dần => Không dùng được cách trên.
 * Trong bài toán này, ta sử dụng PQ, cụ thể:
 *      +) Với mỗi i (s[i]) cần tìm j thỏa mãn j < i: s[i] >= s[j] + k (rõ ràng tại vòng lặp thứ i thì mọi s[j], j < i đều đã biết). 
 *         Chú ý rằng, có 2 điểm đột phá ở đây là:
 *              *) s[i] - s[jmin] >= s[i] - s[j...] >= s[i] - s[jmax]
 *              *) Nếu j đã thỏa mãn s[i] - s[j] >= k, thì rõ ràng tại vòng lặp i + 1 trở đi, ta ko cần xét tiếp s[j] nữa, tại sao? Vì yêu cầu bài toán i - j nhỏ nhất => Dù từ vòng lặp i + 1 có đúng thì cũng ko phải kết quả tối ưu.
 *      +) Từ ý *) thứ 2, ta có thể đưa ra ý tưởng đơn giản là: 
 *          +) Duy trì 1 list L nào đó chứa tập j còn lại, giả sử như đang ở tại vòng lặp thứ i.
 *          +) Ta sẽ duyệt hết tất cả l trong list L (chính là tập chỉ số j), nếu s[i] - s[l] >= k => Cập nhật kết quả shortest, xóa l ra khỏi L.
 *          +) Sau khi duyệt xong, chỉ còn lại tập s[i] - s[l] < k ở trong L.
 *          +) Thêm i vào L để chuẩn bị cho vòng lặp i + 1.
 *      +) Ý tưởng trên hay, tuy nhiên độ phức tạp là bao nhiêu, nếu L chỉ đơn giản là vector
 *         => Về cơ bản việc duyệt toàn bộ L chính là O(n) luôn => Vẫn là O(n^2)
 *         => Cần tìm được cấu trúc dữ liệu phù hợp cho L, sao cho việc duyệt trên toàn bộ vòng lặp (i = 1->N) chỉ có O(nlogn) thôi:
 *              => Chính là sử dụng PQ: Khi đưa prefix sum vào PQ, thì toàn bộ s[l] trong L đã được sort
 *              =>      s[top] <= ... s[l] => s[i] - s[top] >= s[i] - s[...]
 *              => Ta chỉ duyệt PQ cho tới khi gặp l_o: s[i] - s[l_o] < k, lúc đó rõ ràng mọi l còn lại trong L đều có tính chất: s[i] - s[l] <= s[i] - s[l_o] < k
 */
typedef pair<long long, int> lli;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        int shortestLength = INT_MAX;

        vector<long long> S(nums.size()); // S[i] - S[j] = a[j+1] + ... + a[i]. S[0] = a[0], S[1] = a[0] + a[1]...
        S[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            S[i] = S[i-1] + nums[i];
        
        for (int i = 0; i < nums.size(); i++){
            // Nếu S[i] >= k => (0...i) cũng là 1 solution:
            if (S[i] >= k){
                shortestLength = min(shortestLength, i + 1);
            }

            // Tìm l trong tập PQ:
            while (!pq.empty()){
                lli top = pq.top();
                int S_j = top.first, j = top.second;
                if (S[i] - S[j] < k) break;

                shortestLength = min(shortestLength, i - j);
                pq.pop();
            }

            pq.push(lli(S[i], i));
        }
        return (shortestLength == INT_MAX ? -1 : shortestLength);
    }
};

int main(){
    // vector<int> nums = {1};
    // int k = 1;  

    // vector<int> nums = {1, 2};
    // int k = 4;  

    vector<int> nums = {2, -1, 2};
    int k = 3;  

    Solution s;
    cout << s.shortestSubarray(nums, k);
}