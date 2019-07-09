#include <cstdio>
#include <vector>
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
std::vector<int> G[MAXN];
bool seen[MAXN];
int K, N;
int ret;

void dfs(int cur, int sib) {
    seen[cur] = true;
    int sze = G[cur].size();
    // sib != 0 means cur is not root
    int k = (sib) ? 2 : 1;
    for (auto nxt: G[cur]) {
        if (!seen[nxt]) {
            dfs(nxt, k);
            if (k < sze) ++k;
        }
    }
    ret = 1LL * ret * (K - sib) % MOD;
}

int solve() {
    ret = 1;
    for (int i = 1; i <= N; ++i) {
        if (K <= static_cast<int>(G[i].size())) {
            return 0;
        }
    }
    for (int i = 1; i <= N; ++i) if (!seen[i]) {
        dfs(i, 0);
    }
    return ret;
}

int main() {
    scanf(" %d%d", &N, &K);
    for (int i = 1; i < N; ++i) {
        int a, b;
        scanf(" %d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    printf("%d\n", solve());
    return 0;
}
