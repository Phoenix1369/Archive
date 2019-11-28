#include <algorithm>
#include <cstdio>
const int MAXN = 305;
int A[MAXN][MAXN];
int G[MAXN][MAXN];
int L, M, N, Q;

void build_graph() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (G[i][j] <= L) {
                A[i][j] = 1;
            } else {
                A[i][j] = MAXN;
            }
        }
    }
}

void init() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                G[i][j] = 0;
            } else {
                G[i][j] = L + 1;
            }
        }
    }
}

void floyd_warshall(int (&E)[MAXN][MAXN]) {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                E[i][j] = std::min(E[i][k] + E[k][j], E[i][j]);
            }
        }
    }
}

int main() {
    scanf(" %d%d%d", &N, &M, &L);
    init();
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        scanf(" %d%d%d", &a, &b, &c);
        G[a][b] = G[b][a] = c;
    }
    floyd_warshall(G);
    build_graph();
    floyd_warshall(A);
    scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
        int s, t;
        scanf(" %d%d", &s, &t);
        if (A[s][t] < MAXN) {
            printf("%d\n", A[s][t] - 1);
        } else {
            puts("-1");
        }
    }
    return 0;
}
