#include <cstdio>
const int MAXN = 1e5+5;
int A[MAXN], rain[MAXN];
int N;

/*
A[0] = A[N]
M[N+1] = M[1]

A[i] = M[i] + M[i+1]
M[i] = M[1] + sum_(j=1)^(i-1) A[j] * (-1)^(i - j - 1)

A[N] = M[N] + M[1]
M[N] = M[1] + sum_(j=1)^(N-1) A[j] * (-1)^(N - j - 1)
*/

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    rain[1] = A[N];
    for (int i = 1; i < N; ++i) {
        if ((N - i) & 1) {
            rain[1] -= A[i];
        } else {
            rain[1] += A[i];
        }
    }
    rain[1] >>= 1;
    for (int i = 2; i <= N; ++i) {
        rain[i] = A[i-1] - rain[i-1];
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d ", rain[i] * 2);
    }
    putchar('\n');
    return 0;
}
