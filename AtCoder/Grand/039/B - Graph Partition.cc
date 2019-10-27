#include <cstdio>
#include <vector>
const int MAXN = 205;
const int NOPE = -1;
int A[MAXN][MAXN];
int C[MAXN];
char S[MAXN];
int N;

bool dfs(int cur) {
    for (int nxt = 1; nxt <= N; ++nxt) {
        if ((cur == nxt) || (A[cur][nxt] == MAXN)) {
            continue;
        }
        if (C[nxt] == C[cur]) {
            return false;
        }
        if (C[nxt] == NOPE) {
            C[nxt] = C[cur] ^ 1;
            if (!dfs(nxt)) {
                return false;
            }
        }
    }
    return true;
}

void floyd_warshall() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                A[i][j] = std::min(A[i][k] + A[k][j], A[i][j]);
            }
        }
    }
}

int solve(int src) {
    C[src] = 0;
    if (!dfs(src)) {
        return NOPE;
    }
    floyd_warshall();
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ret = std::max(A[i][j], ret);
        }
    }
    return ret + 1;
}

void init() {
    for (int i = 1; i <= N; ++i) {
        C[i] = NOPE;
    }
}

int main() {
    scanf("%d", &N);
    init();
    for (int i = 1; i <= N; ++i) {
        scanf("%s", S+1);
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                A[i][j] = 0;
            } else if (S[j] - '0') {
                A[i][j] = 1;
            } else {
                A[i][j] = MAXN;
            }
        }
    }
    printf("%d\n", solve(1));
    return 0;
}
