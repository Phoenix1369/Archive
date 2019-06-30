#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        int two = 1;
        while (two <= label) two <<= 1;
        two >>= 1;
        while (label >= 1) {
            ret.push_back(label);
            label = (two >> 1) + (two - 1) - (label >> 1);
            two >>= 1;
        }
        reverse(ALL(ret));
        return ret;
    }
};
