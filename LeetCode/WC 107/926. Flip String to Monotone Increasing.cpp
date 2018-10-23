const int MAXN = 2e4+5;
int zero[MAXN]{ };

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = (int)S.size();
        zero[n] = 0;
        for (int i = n-1; i >= 0; --i) {
            if (S[i] == '0') {
                zero[i] = zero[i+1] + 1;
            } else {
                zero[i] = zero[i+1];
            }
        }
        int one = 0;
        int ret = MAXN;
        for (int i = 0; i < n; ++i) {
            ret = min(one+zero[i], ret);
            if (S[i] == '1') {
                ++one;
            }
        }
        ret = min(one, ret);
        return ret;
    }
};
