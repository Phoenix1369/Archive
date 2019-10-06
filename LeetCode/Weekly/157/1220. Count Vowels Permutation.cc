const int MAXN = 2e4+5;
const int MAXV = 5;
const int MOD = 1e9+7;
const vector<int> moves[MAXV] = {
    {1},
    {0, 2},
    {0, 1, 3, 4},
    {2, 4},
    {0}
};
int dp[MAXN][MAXV];
int N;

class Solution {
public:
    int countVowelPermutation(int n) {
        N = n;
        init();
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < MAXV; ++j) {
                for (auto k: moves[j]) {
                    dp[i+1][k] = (1LL * dp[i][j] + dp[i+1][k]) % MOD;
                }
            }
        }
        int ret = 0;
        for (int j = 0; j < MAXV; ++j) {
            ret = (1LL * dp[N][j] + ret) % MOD;
        }
        return ret;
    }
    
private:
    void init() {
        for (int j = 0; j < MAXV; ++j) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j < MAXV; ++j) {
                dp[i][j] = 0;
            }
        }
    }
};
