#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RangeFreqQuery {
private:
    struct Block {
        unordered_map<int, int> freq;
    };

    std::vector<Block> blocks;
    int n_blocks;
    int max_block_size;
    const vector<int>& arr;

    int bstart(int r){
        return (r / max_block_size) * max_block_size;
    }

    int bend(int r){
        return min((int)arr.size(), ((r / max_block_size) + 1) * max_block_size);
    }

public:
    RangeFreqQuery(vector<int>& arr) : arr(arr){
        int n = arr.size();
        max_block_size  = ceil(sqrt(n));
        n_blocks = ceil(1. * n / max_block_size);
        blocks.resize(n_blocks);
        for (int blk_id=-1, i = 0; i < n; ++i){
            if (i % max_block_size == 0) ++blk_id;
            blocks[blk_id].freq[arr[i]]++;
        }
    }
    
    int query(int left, int right, int value) {
        int l_blk = left / max_block_size;
        int r_blk = right / max_block_size;
        int ans = 0;
        if (l_blk == r_blk){
            for (int i = left; i <= right; ++i)
                ans += (arr[i] == value);
        }
        else {
            for (int i = left; i < bend(left); ++i)
                ans += (arr[i] == value);
            for (int blk = l_blk+1; blk <= r_blk-1; ++blk)
                ans += blocks[blk].freq[value];
            for (int i = bstart(right); i <= right; ++i)
                ans += (arr[i] == value);
        }
        return ans;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */