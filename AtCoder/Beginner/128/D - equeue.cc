#include <cstdio>
#include <iterator>
#include <queue>
const int INFT = 1e9+7;
const int MAXN = 55;
const int MAXK = 105;
int dp[MAXN][MAXN][MAXK];
int V[MAXN];
int K, N;

int dfs(int l, int r, int m) {
    if (dp[l][r][m] != -INFT) {
        return dp[l][r][m];
    }
    int sum = 0;
    std::priority_queue<int> heap;
    for (int i = 1; i <= N; ++i) if ((i <= l) || (r <= i)) {
        sum += V[i];
        if (V[i] < 0) heap.push(-V[i]);
    }
    if (!m) {
        return dp[l][r][m] = sum;
    }
    // Operations C and D.
    for (int k = 0; (k < m) && !heap.empty(); ++k) {
        sum += heap.top();
        heap.pop();
    }
    // Operations A and B.
    if (l < r) {
        sum = std::max(dfs(l+1, r, m-1), sum);
        sum = std::max(dfs(l, r-1, m-1), sum);
    }
    return dp[l][r][m] = sum;
}

int main() {
    scanf(" %d%d", &N, &K);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &V[i]);
    }
    for (int i = 0; i <= N + 1; ++i) {
        for (int j = 0; j <= N + 1; ++j) {
            for (int k = 0; k <= K; ++k) {
                dp[i][j][k] = -INFT;
            }
        }
    }
    printf("%d\n", dfs(0, N + 1, K));
    return 0;
}
