const int MAXN = 1005;

class Solution {
    bitset<MAXN> dp;

    void step(bool* ret, int n, int x) {
        int y = n - x;
        if ((0 < y) && (y < n)) {
            *ret &= dp[y];
        }
    }

public:
    bool divisorGame(int N) {
        dp.reset();
        for (int i = 2; i <= N; ++i) {
            int s = sqrt(i);
            bool ret = true;
            for (int j = 1; j <= s; ++j) if ((i % j) == 0) {
                step(&ret, i, j);
                step(&ret, i, i / j);
            }
            dp.set(i, !ret);
        }
        return dp[N];
    }
};
