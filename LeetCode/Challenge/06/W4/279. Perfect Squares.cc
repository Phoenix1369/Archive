const int MAXN = 1e4+5;
int memo[MAXN]{ };
int M = 0;

class Solution {
public:
    int numSquares(int n) {
        // memo[0] = 0;
        for (int i = M+1; i <= n; ++i) {
            memo[i] = MAXN;
            for (int j = sqrt(i); j >= 1; --j) {
                memo[i] = min(memo[i - j*j] + 1, memo[i]);
            }
        }
        M = max(n, M);
        return memo[n];
    }
};
