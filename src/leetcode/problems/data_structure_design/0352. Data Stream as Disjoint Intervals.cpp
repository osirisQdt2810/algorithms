#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class SummaryRanges {
private:
    struct Info {
        int left{-1};
        int right{-1};
    };

    unordered_map<int, Info> infos;
    set<int> ans;

public:
    SummaryRanges() {
    }
    
    void addNum(int value) {
        if (infos.find(value) != infos.end()) return;
        infos[value] = Info{value, value};

        int l = value - 1;
        int r = value + 1;
        bool exist_left = (infos.find(l) != infos.end());
        bool exist_right = (infos.find(r) != infos.end());

        if (exist_left && exist_right){
            int start = infos[l].left;
            int end = infos[r].right;
            infos[start].right = end;
            infos[end].left = start;
            ans.erase(r);
            return;
        }
        if (exist_left){
            int start = infos[l].left;
            int end = value;
            infos[start].right = end;
            infos[end].left = start;
            return;
        }
        if (exist_right){
            int start = value;
            int end = infos[r].right;
            infos[start].right = end;
            infos[end].left = start;
            ans.erase(r);
            ans.insert(start);
            return;
        }
        ans.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& start : ans){
            res.push_back({start, infos[start].right});
        }
        return res;
    }
    //
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */