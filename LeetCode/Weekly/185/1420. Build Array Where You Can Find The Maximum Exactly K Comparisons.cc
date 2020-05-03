const int MAXM = 105;
const int MAXN = 55;
const int MOD = 1e9+7;
int dp[MAXN][MAXM][MAXN];
int K, M, N;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        init();
        return dfs(0, 0, 0);
    }

private:
    int dfs(int i, int mx, int cost) {
        if (i == N) {
            return (cost == K);
        }
        if (cost > K) return 0;
        if (dp[i][mx][cost] != -1) {
            return dp[i][mx][cost];
        }
        int ret = 0;
        for (int j = 1; j <= M; ++j) {
            int nc = cost;
            int nx = max(j, mx);
            if (mx < nx) ++nc;
            ret = (dfs(i+1, nx, nc) + ret) % MOD;
        }
        return dp[i][mx][cost] = ret;
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= M; ++j) {
                for (int k = 0; k <= N; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }
};
