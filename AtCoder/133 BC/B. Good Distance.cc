#include <cmath>
#include <cstdio>
const int MAXN = 10;
int X[MAXN][MAXN];
int D, N;

int main() {
    scanf(" %d%d", &N, &D);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < D; ++j) {
            scanf("%d", &X[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dd = 0;
            for (int k = 0; k < D; ++k) {
                int dk = (X[i][k] - X[j][k]);
                dd += dk * dk;
            }
            int ds = sqrt(dd);
            if (ds * ds == dd) {
                ++cnt;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
