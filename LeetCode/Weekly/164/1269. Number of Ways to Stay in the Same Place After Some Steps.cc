const int MAXN = 505;
const int MOD = 1e9 + 7;
const int NOPE = -1;
int dp[MAXN][MAXN];
int K, M, N;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        K = steps;
        N = arrLen;
        init();
        return dfs(K, 0);
    }

private:
    int dfs(int steps, int cur) {
        if ((cur < 0) || (cur >= M) || (steps < 0)) {
            return 0;
        }
        if (dp[steps][cur] != NOPE) {
            return dp[steps][cur];
        }
        int res = 0;
        res = (dfs(steps - 1, cur - 1) + res) % MOD;
        res = (dfs(steps - 1, cur    ) + res) % MOD;
        res = (dfs(steps - 1, cur + 1) + res) % MOD;
        return dp[steps][cur] = res;
    }
    
    void init() {
        M = min(K + 1, N);
        for (int j = 0; j < M; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= K; ++i) {
            for (int j = 0; j < M; ++j) {
                dp[i][j] = NOPE;
            }
        }
        dp[0][0] = 1;
    }
};

/*
3
2
2
4
4
2
>> 4
>> 2
>> 8
*/
