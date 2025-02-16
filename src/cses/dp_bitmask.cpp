// #include <bits/stdc++.h>
 
// using namespace std;
 
// const int N=20,M=1<<N;
 
// int n,x;
// int a[N];
// pair<int,int> dp[M];
 
// signed main()
// {
// //    freopen("a.inp","r",stdin);freopen("a.out","w",stdout);
//     ios_base::sync_with_stdio(0);cin.tie(0);
 
//     cin>>n>>x;
//     for (int i=0;i<n;i++)
//         cin>>a[i];
 
//     dp[0]={1,0};
//     for (int mask=1;mask<(1<<n);mask++)
//     {
//         dp[mask]={n,0};
//         for (int i=0;i<n;i++)
//             if (mask>>i&1)
//             {
//                 auto tmp=dp[mask^(1<<i)];
//                 if (tmp.second+a[i]>x)
//                     tmp={tmp.first+1,a[i]};
//                 else
//                     tmp.second+=a[i];
 
//                 dp[mask]=min(dp[mask],tmp);
//             }
//     }
 
//     cout<<dp[(1<<n)-1].first;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    int w[n];
    for (int i=0;i<n;i++){
        cin >> w[i];
    }
    pair<int,int> best[1<<n];
    best[0]={1,0};
    for (int i=1;i<(1<<n);i++){
        // Initialize worse than worst case: Take n+1 rides
        best[i] = {n+1,0};
        for (int j=0;j<n;j++){
            // If j-th person is in i-th subset
            int x = i&(1<<j);
            if (i&(1<<j)){
                // Consider option for j-th person: Add to existing ride or new ride
                // Exclude j-th person first
                auto option = best[i^(1<<j)];
                if (option.second+w[j]<=x){
                    option.second += w[j];
                }
                else {
                    option.first ++;
                    option.second = w[j];
                }
                // Store better option based on number of rides
                best[i] = min(best[i],option);
            }
        }
    }
    cout << best[(1<<n)-1].first;
    return 0;
}