map<pair<int,int>, int> cnt;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        cnt.clear();
        for (auto& d: dominoes) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            ++cnt[make_pair(d[0], d[1])];
        }
        int ret = 0;
        for (auto& itr: cnt) {
            int y = itr.second;
            ret += y * (y - 1) / 2;
        }
        return ret;
    }
};
