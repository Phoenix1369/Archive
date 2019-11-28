#include <cstdio>
const int MAXN = 55;
int D[MAXN];
int N;

int solve() {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += D[i] * D[j];
        }
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &D[i]);
    }
    printf("%d\n", solve());
    return 0;
}
