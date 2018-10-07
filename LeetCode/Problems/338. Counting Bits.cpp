class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret {0};
        unordered_map<int,int> LOG2(32);
        for (int i=0, j=1; i < 32; ++i, j <<= 1) {
            LOG2[j] = i;
        }
        for (int i = 1; i <= num; ++i) {
            if (i & 1) {
                ret.push_back(ret.back() + 1);
            } else {
                ret.push_back(ret.back() - LOG2.at(i & -i) + 1);
            }
        }
        return ret;
    }
};
