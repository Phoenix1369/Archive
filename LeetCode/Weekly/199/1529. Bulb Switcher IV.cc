class Solution {
public:
    int minFlips(string target) {
        char cur = '0';
        int ret = 0;
        int N = target.size();
        for (int i = 0; i < N; ++i) {
            if (cur != target[i]) {
                cur ^= 1;
                ++ret;
            }
        }
        return ret;
    }
};
