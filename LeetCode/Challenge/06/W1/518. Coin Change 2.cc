#define CLR(x) memset((x), -1, sizeof(x))
const int MAXA = 5005;
const int MAXN = 505;
int dp[MAXN][MAXA];
vector<int> C;
int K, N;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        K = amount;
        C = move(coins);
        N = C.size();
        CLR(dp);
        return dfs(0, 0);
    }

private:
    int dfs(int pos, int val) {
        if (pos == N) {
            return (val == K) ? 1 : 0;
        }
        if (dp[pos][val] != -1) {
            return dp[pos][val];
        }
        int ret = 0;
        int sum = val;
        for (int i = 0; sum <= K; ++i) {
            ret += dfs(pos + 1, sum);
            sum += C[pos];
        }
        return dp[pos][val] = ret;
    }
};
