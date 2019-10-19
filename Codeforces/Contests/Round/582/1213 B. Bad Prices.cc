#include <cstdio>
const int MAXA = 1e6 + 5;
const int MAXN = 1.5e5+5;
int A[MAXN];
int N, T;

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        int ret = 0;
        int M = MAXA;
        for (int i = N-1; i >= 0; --i) {
            if (A[i] > M) ++ret;
            else M = A[i];
        }
        printf("%d\n", ret);
    }
    return 0;
}
