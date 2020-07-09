#include <cstring>
#include <cstdio>
const int MAXN = 1005;
char X[MAXN];
char Y[MAXN];
int K, N, T;

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf(" %s", X);
        scanf("%d", &K);
        N = strlen(X);
        for (int i = 0; i < N; ++i) {
            if ((K > 0) && (X[i] == '0')) {
                Y[i] = '1';
                --K;
            } else {
                Y[i] = '0';
            }
        }
        Y[N] = '\0';
        puts(Y);
    }
    return 0;
}
