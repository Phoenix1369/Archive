#include <cstdio>
#include <vector>
const int MAXN = 605;
double dp[MAXN];
std::vector<int> G[MAXN];
int M, N;

// 1. Fix an edge to block
// 2. Try blocking every edge
// 3. Only need to consider blocking worst outgoing edge for each node
// 4. Fix a node to block outgoing edges
// 5. Try blocking only the worst edge

double solve(int node) {
    // Block outgoing edges from `node` only
    for (int i = 1; i <= N; ++i) {
        dp[i] = 0.0;
    }
    for (int i = N-1; i >= 1; --i) {
        int K = G[i].size();
        if (K == 1) {
            dp[i] = dp[G[i][0]] + 1.0;
            continue;
        }
        double max = 0.0;
        double sum = 0.0;
        int skip = 1;
        for (auto nxt: G[i]) {
            sum += dp[nxt];
            max = std::max(dp[nxt], max);
        }
        if (i != node) {
            max = 0.0;
            skip = 0;
        }
        dp[i] = 1.0 * (sum - max) / (K - skip) + 1.0;
    }
    return dp[1];
}

int main() {
    scanf(" %d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int s, t;
        scanf(" %d%d", &s, &t);
        G[s].push_back(t);
    }
    double ret = N;
    for (int i = 1; i <= N; ++i) {
        ret = std::min(solve(i), ret);
    }
    printf("%.9f\n", ret);
    return 0;
}
