#include <algorithm>
#include <cstdio>
#define PROBLEM "graphs_as_a_service"
#define SOLVE
const int INFN = 1e6+1;
const int MAXM = 1005;
const int MAXN = 55;
int A[MAXN][MAXN];
int X[MAXM], Y[MAXM], Z[MAXM];
int M, N, T;

void floyd_warshall() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                A[i][j] = std::min(A[i][k] + A[k][j], A[i][j]);
            }
        }
    }
}

bool solve() {
    floyd_warshall();
    for (int i = 0; i < M; ++i) {
        int x = X[i];
        int y = Y[i];
        if ((A[x][y] != Z[i]) || (A[y][x] != Z[i])) {
            return false;
        }
    }
    return true;
}

void init() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                A[i][j] = 0;
            } else {
                A[i][j] = INFN;
            }
        }
    }
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
        scanf(" %d%d", &N, &M);
        init();
        for (int i = 0; i < M; ++i) {
            int x, y;
            scanf(" %d%d", &x, &y);
            X[i] = x;
            Y[i] = y;
            scanf("%d", &Z[i]);
            A[x][y] = A[y][x] = Z[i];
        }

        printf("Case #%d: ", t);
        if (solve()) {
            printf("%d\n", M);
            for (int i = 0; i < M; ++i) {
                printf("%d %d %d\n", X[i], Y[i], Z[i]);
            }
        } else {
            puts("Impossible");
        }
    }
    return 0;
}
