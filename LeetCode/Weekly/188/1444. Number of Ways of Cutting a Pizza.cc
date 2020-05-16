const int MAXK = 11;
const int MAXN = 55;
const int MOD = 1e9+7;
int dp[MAXN][MAXN][MAXK];
int A[MAXN][MAXN];
vector<string> P;
int K, M, N;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        P = move(pizza);
        N = P.size();
        M = P[0].size();
        K = k;
        init();
        return dfs(1, 1, K);
    }

private:
    int dfs(int r, int c, int k) {
        if (dp[r][c][k] != -1) {
            return dp[r][c][k];
        }
        if (k == 1) {
            return dp[r][c][k] = (A[r][c] ? 1 : 0);
        }
        int res = 0;
        for (int i = r+1; i <= N; ++i) {
            if (A[r][c] == A[i][c]) continue;
            res = (1LL * res + dfs(i, c, k-1)) % MOD;
        }
        for (int j = c+1; j <= M; ++j) {
            if (A[r][c] == A[r][j]) continue;
            res = (1LL * res + dfs(r, j, k-1)) % MOD;
        }
        return dp[r][c][k] = res;
    }
    
    void init() {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= M; ++j) {
                for (int k = 0; k <= K; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (int i = 0; i <= N; ++i) A[i][M+1] = 0;
        for (int j = 0; j <= M; ++j) A[N+1][j] = 0;
        // Grid
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i+1][j+1] = (P[i][j] == 'A') ? 1 : 0;
            }
        }
        for (int i = N; i >= 1; --i) {
            for (int j = 1; j <= M; ++j) {
                A[i][j] += A[i+1][j];
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = M; j >= 1; --j) {
                A[i][j] += A[i][j+1];
            }
        }
    }
};
