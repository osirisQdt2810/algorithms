#include <iostream>
#include <memory>
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a[20];
int rule[20][20];
long long dp[1<<20][20];

int get_bit(int bitmask, int i){
    return (bitmask >> i) & 1;
}

long long backtrack(int bitmask, int last, int mo){
    if (mo == m) return 0;
    long long res = 0;

    for (int i = 0; i < n; ++i){
        if (get_bit(bitmask, i)) continue;

        int n_bitmask = bitmask ^ (1 << i);
        long long sub_res = backtrack(n_bitmask, i, mo + 1);
        res = max(res, sub_res + a[i] + rule[last][i]);
    }
    cout << "bitmask = " << bitmask << " last = " << last << " res = " << res << "| mo = " << mo << "\n";
    return res;
}


long long dynamic_programming(int bitmask, int last, int mo){
    long long& res = dp[bitmask][last];
    if (res != -1) return res;

    if (mo == m) return 0;
    res = 0;
    for (int i = 0; i < n; ++i){
        if (get_bit(bitmask, i)) continue;

        int n_bitmask = bitmask ^ (1 << i);
        long long sub_res = dynamic_programming(n_bitmask, i, mo + 1);
        res = max(res, sub_res + a[i] + rule[last][i]);
    }
    // cout << "bitmask = " << bitmask << " last = " << last << " res = " << res << "| mo = " << mo << "\n";
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
    #endif

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int x, y, a, i = 0; i < k; ++i){
        cin >> x >> y >> a;
        rule[y - 1][x - 1] = a;
    }

    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= n; ++j)
    //         cout << i << " " << j << " " << rule[i][j] << "\n";

    // bitmask: (000...0)0
    memset(dp, -1, sizeof(dp));
    // cout << backtrack(0, n, 0);
    cout << dynamic_programming(0, n, 0);

    return 0;
}