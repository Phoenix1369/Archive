const int MAXN = 505;
int Z[MAXN];
int N;

class Solution {
public:
    int maxScore(string s) {
        N = s.size();
        Z[0] = 0;
        for (int i = 1; i <= N; ++i) {
            Z[i] = Z[i-1] + (s[i-1] == '0');
        }
        int ret = 0;
        for (int i = 1; i < N; ++i) {
            int all = N - i;
            int zer = Z[N] - Z[i];
            int val = Z[i] + (all - zer);
            ret = max(val, ret);
        }
        return ret;
    }
};
