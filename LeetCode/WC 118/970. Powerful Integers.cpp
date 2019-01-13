#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ret;
        int a = 1;
        for (int i = 0; (a <= bound) && ((x != 1) || !i); ++i, a *= x) {
            int b = 1, c;
            for (int j = 0; ((c = a + b) <= bound) && ((y != 1) || !j); ++j, b *= y) {
                ret.push_back(c);
            }
        }
        sort(ALL(ret));
        ret.erase(unique(ALL(ret)), ret.end());
        return ret;
    }
};
