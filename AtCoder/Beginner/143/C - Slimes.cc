#include <cstdio>
const int MAXN = 1e5+5;
char S[MAXN];
int N;

int solve() {
    int sum = 1;
    for (int i = 1; i < N; ++i) {
        if (S[i] != S[i-1]) ++sum;
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    scanf(" %s", S);
    printf("%d\n", solve());
    return 0;
}
