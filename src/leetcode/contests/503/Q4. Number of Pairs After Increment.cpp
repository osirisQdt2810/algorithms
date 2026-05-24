#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private: 
    int ceil(int a, int b){
        return (a + b - 1) / b;
    }

    using ll = long long;

    struct bucket {
        unordered_map<ll, int> freq;
        ll lazy{0};
    };

public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2_, vector<vector<int>>& queries) {
        int n = nums2_.size();
        vector<ll> nums2(nums2_.begin(), nums2_.end());
        int bucket_size = sqrt(n);
        int n_buckets = ceil(n, bucket_size);

        vector<bucket> buckets(n_buckets);
        for (int b = 0; b < n_buckets; ++b){
            int l = min(n-1, b * bucket_size);
            int r = min(n, (b+1) * bucket_size);
            for (int i = l; i < r; ++i){
                buckets[b].freq[nums2[i]]++;
            }
        }

        // cout << "nums2: " << n << "\n";
        // cout << "n_buckets: " << n_buckets << endl;
        // cout << "bucket_size: " << bucket_size << endl;

        vector<int> res;
        for (auto& query : queries){
            int qlen = query.size();
            if (qlen == 4){ // type1

                int l = query[1], r = query[2];
                int val = query[3];
                // add val into nums2[l, r]
                int l_bucket = l / bucket_size;
                int r_bucket = r / bucket_size;

                // cout << "query:" << l << " " << r << " " << val << endl;

                // update val to lazy for [l_bucket+1, r_bucket-1]
                for (int b = l_bucket+1; b < r_bucket; ++b)
                    buckets[b].lazy += val;

                // update val for l_bucket
                if (l % bucket_size == 0 && (r - l >= bucket_size)){
                    buckets[l_bucket].lazy += val;
                }
                else {
                    int end = min(r+1, (l_bucket + 1) * bucket_size);
                    for (int i = l; i < end; ++i){
                        if (--buckets[l_bucket].freq[nums2[i]] == 0){
                            buckets[l_bucket].freq.erase(nums2[i]);
                        }
                        nums2[i] += val;
                        buckets[l_bucket].freq[nums2[i]]++;
                    }
                }

                // update val for r_bucket
                if (l_bucket == r_bucket) continue;  // already updated
                if ((r+1) % bucket_size == 0){
                    buckets[r_bucket].lazy += val;
                }
                else {
                    int start = min(n-1, r_bucket * bucket_size);
                    for (int i = start; i <= r; ++i){
                        if (--buckets[r_bucket].freq[nums2[i]] == 0){
                            buckets[r_bucket].freq.erase(nums2[i]);
                        }
                        nums2[i] += val;
                        buckets[r_bucket].freq[nums2[i]]++;
                    }
                }
            }
            else {  // type 2
                ll target = query[1];
                // count for each bucket
                // cout << "query:" << " - target: " << target << endl;
                int ans = 0;
                for (auto& num1 : nums1){
                    for (auto& bucket: buckets){
                        ans += bucket.freq[target - bucket.lazy - num1];
                    }
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};

// int main(){
//     Solution sol;
//     vector<int> nums1{35,10,65,92,30};
//     vector<int> nums2{1,18,46,69,64,14,45,33,5,27,81,18,6,81,58,30,83,22,3,3,30,2,93,48,13,53,85,68,87,82,60,7,9,48,88,42,15,57,71,22,91,14,47,3,10,72,41};
//     vector<vector<int>> queries{{2,87},{1,13,14,99},{2,98},{2,71},{2,121},{2,112},{2,67},{1,17,17,62},{2,93}};
//     auto res = sol.numberOfPairs(nums1, nums2, queries);
//     for (auto r : res){
//         cout << r << endl;
//     }

//     return 0;
// }©leetcode