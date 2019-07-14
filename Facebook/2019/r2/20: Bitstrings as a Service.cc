#include <algorithm>
#include <cstdio>
#include <vector>
#define PROBLEM "bitstrings_as_a_service"
#define SOLVE
const int MAXN = 4005;
const int MAXK = MAXN;
std::vector<int> G[MAXN];
int color[MAXN];
bool seen[MAXN];
char output[MAXN];
int M, N, T;

bool dp[MAXK][MAXN];

// Components
int R[MAXK]; // Root
int S[MAXK]; // Size
int K; // Amount

void dfs(int cur) {
    if (seen[cur]) {
        return;
    }
    color[cur] = K;
    seen[cur] = true;
    ++S[K];
    for (auto nxt: G[cur]) {
        dfs(nxt);
    }
}

void dfs2(int cur, char v) {
    if (seen[cur]) {
        return;
    }
    seen[cur] = true;
    output[cur] = v;
    for (auto nxt: G[cur]) {
        if (color[nxt] == color[cur]) {
            dfs2(nxt, v);
        }
    }
}

void construct(int j) {
    for (int i = 0; i <= N; ++i) {
        seen[i] = false;
    }
    for (int i = K; i > 0; --i) {
        if ((j >= S[i]) && dp[i-1][j - S[i]]) {
            dfs2(R[i], '0');
            j -= S[i];
        } else {
            dfs2(R[i], '1');
        }
    }
}

void init() {
    for (int i = 0; i <= N; ++i) {
        color[i] = 0;
        dp[0][i] = false;
        G[i].clear();
        R[i] = 0;
        S[i] = 0;
        seen[i] = false;
    }
    output[N+1] = '\0';
    K = 0;
}

void exec(int t) {
    scanf(" %d%d", &N, &M);
    init();
    for (int i = 0; i < M; ++i) {
        int X, Y;
        scanf(" %d%d", &X, &Y);
        while (X < Y) {
            G[X].push_back(Y);
            G[Y].push_back(X);
            ++X;
            --Y;
        }
    }

    for (int i = 1; i <= N; ++i) if (!seen[i]) {
        ++K;
        R[K] = i;
        dfs(R[K]);
    }

    dp[0][0] = true;
    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j <= N; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= S[i]) {
                dp[i][j] |= dp[i-1][j - S[i]];
            }
        }
    }

    // Minimal Difference
    int best = 0;
    while (!dp[K][best]) ++best;
    for (int i = best+1; i <= N; ++i) if (dp[K][i]) {
        if (abs(N-2*best) > abs(N-2*i)) {
            best = i;
        }
    }
    construct(best);
}

int main() {
#ifndef SOLVE
    freopen(PROBLEM "_sample_input.txt", "r", stdin);
#else
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif // SOLVE
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        exec(t);
        printf("Case #%d: %s\n", t, output + 1);
    }
    return 0;
}
