class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        int two = 0;
        for (int i = 1; i <= num; ++i) {
            if (i == (i & -i)) {
                ret[i] = 1;
                two = i;
            } else {
                ret[i] = ret[i - two] + 1;
            }
        }
        return ret;
    }
};
