class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ret = 0;
        while (X < Y) {
            if (Y & 1) {
                ++Y;
                ++ret;
            }
            Y >>= 1;
            ++ret;
        }
        ret += X-Y;
        return ret;
    }
};
