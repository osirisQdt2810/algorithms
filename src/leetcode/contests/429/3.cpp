#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string& s, vector<int>& distinct, int numOps, int len){
        int cnt = 0;
        for (int i = 0; i < distinct.size(); ++i){
            if (i > 0 && i < distinct.size() - 1 && len == 1 && distinct[i] % 2 == 0){
                return false;
            }
            cnt += distinct[i] / (len + 1);
        }
        return cnt <= numOps;
    }

    std::vector<int> getContiguousCounts(const std::string &s) {
        std::vector<int> counts;
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            // Current run character
            char current_char = s[i];
            int count = 1; 
            int j = i + 1;
            
            // Count how many times current_char repeats
            while (j < n && s[j] == current_char) {
                ++count;
                ++j;
            }
            
            // Store the count in the result
            counts.push_back(count);
            
            // Move 'i' past this run
            i = j;
        }
        return counts;
    }

    int minLength(string s, int numOps) {
        vector<int> counts = getContiguousCounts(s);
        // for (auto c : counts)
        //     cout << c << " ";
        // cout << "\n";

        int l = 1, r = s.size(), ans = -1;
        while (l <= r){
            int m = (l + r) / 2;
            if (isValid(s, counts, numOps, m)){
                ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return ans;
    }
};

/*
  Mục tiêu: Kiểm tra với độ dài run tối đa = maxRun, ta có thể
  flip <= numOps bit hay không, để không có run nào vượt quá maxRun.
  
  Ta dùng 1 DP 4 chiều:
    dp[i][used][lastBit][curLen] = true/false

  - i: chỉ số đang xét (0-based)
  - used: số bit đã flip đến vị trí i
  - lastBit: bit cuối cùng (0 hoặc 1) sau khi quyết định flip ở vị trí i
  - curLen: độ dài run liên tiếp của lastBit tính tới i

  Điều kiện:
    - Nếu curLen > maxRun => không hợp lệ
    - used <= numOps
*/

bool canAllRunsBeAtMost(vector<int>& sBin, int n, int numOps, int maxRun) {
    // dp[i][used][lastBit][curLen]
    // Để tối ưu bộ nhớ, có thể dùng rolling array theo i, thay vì dp cho toàn bộ i
    static bool dp[2][1010][2][1010]; 
    // Tùy vào constraints, có thể phải dùng động cấp phát,
    // hoặc giảm bớt chiều. Ở đây chỉ minh họa.

    // Ta giả sử n <= 1000 và numOps <= 1000 để code demo;
    // nếu lớn hơn phải tối ưu tiếp.

    // Xóa dữ liệu cũ
    memset(dp, false, sizeof(dp));

    // Trạng thái ban đầu: i = -1, chưa có bit cuối, ta có thể đặt như sau:
    // Thay vào đó, ta khởi tạo dp cho i=0 (phần tử đầu).
    int i0 = sBin[0]; // bit đầu tiên

    // Không flip
    dp[0][0][i0][1] = true;
    // Flip
    dp[0][1][1 - i0][1] = true;

    // Nếu maxRun < 1 => auto fail (vì bất kỳ run length = 1 cũng > 0).
    if (maxRun < 1) return false;

    // i chạy từ 1 -> n-1
    for (int i = 1; i < n; i++) {
        int curBit = sBin[i];
        // Chỉ số dòng trong dp (rolling)
        int now = i % 2;
        int prev = 1 - now;

        // Reset dp[now][...]
        memset(dp[now], false, sizeof(dp[now]));

        // Xét mọi trường hợp i-1
        for (int used = 0; used <= numOps; used++) {
            for (int lastB = 0; lastB < 2; lastB++) {
                for (int lengthRun = 1; lengthRun <= maxRun; lengthRun++) {
                    if (!dp[prev][used][lastB][lengthRun]) {
                        continue;
                    }
                    // Đã có trạng thái hợp lệ ở i-1, lastBit=lastB, run=lengthRun

                    // 1) Không flip s[i]
                    {
                        int newBit = curBit;
                        int newUsed = used;
                        if (newBit == lastB) {
                            int newLen = lengthRun + 1;
                            if (newLen <= maxRun) {
                                dp[now][newUsed][lastB][newLen] = true;
                            }
                        } else {
                            // Bắt đầu run mới
                            dp[now][newUsed][newBit][1] = true;
                        }
                    }

                    // 2) Flip s[i]
                    if (used < numOps) {
                        int newUsed = used + 1;
                        int newBit = 1 - curBit; // bit sau flip
                        if (newBit == lastB) {
                            int newLen = lengthRun + 1;
                            if (newLen <= maxRun) {
                                dp[now][newUsed][lastB][newLen] = true;
                            }
                        } else {
                            dp[now][newUsed][newBit][1] = true;
                        }
                    }
                }
            }
        }
    }

    // Sau khi duyệt xong i = n-1:
    int last = (n-1) % 2;
    // Kiểm tra có trạng thái nào true với used <= numOps
    for (int used = 0; used <= numOps; used++) {
        for (int lastB = 0; lastB < 2; lastB++) {
            for (int lengthRun = 1; lengthRun <= maxRun; lengthRun++) {
                if (dp[last][used][lastB][lengthRun]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int minLength(string s, int numOps) {
    int n = (int)s.size();
    // Convert string -> vector<int> (0/1)
    vector<int> sBin(n);
    for (int i = 0; i < n; i++) {
        sBin[i] = (s[i] == '1') ? 1 : 0;
    }

    // Binary Search trên L = 1 .. n
    int left = 1;
    int right = n;
    int ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;
        // Kiểm tra có thể đưa mọi run <= mid không
        if (canAllRunsBeAtMost(sBin, n, numOps, mid)) {
            ans = mid;
            right = mid - 1;  // thử xem có nhỏ hơn nữa không
        } else {
            left = mid + 1;   // cần tăng mid
        }
    }

    return ans;
}

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    string s = "0110";
    int numOps = 2;
    cout << sol.minLength(s, numOps);
}