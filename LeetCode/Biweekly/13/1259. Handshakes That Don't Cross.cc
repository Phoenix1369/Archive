const int MAXN = 1005;
const int MOD = 1e9+7;
int dp[MAXN];
int N;

class Solution {
public:
    int numberOfWays(int num_people) {
        N = num_people;
        init();
        return dfs(N);
    }

private:
    int dfs(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        if (n == 0) {
            return dp[n] = 1;
        }
        int sum = 0;
        for (int i = 2; i <= n; i += 2) {
            sum = (1LL * dfs(i-2) * dfs(n-i) % MOD + sum) % MOD;
        }
        return dp[n] = sum;
    }
    
    void init() {
        for (int i = 0; i <= N; ++i) {
            dp[i] = -1;
        }
    }
};
