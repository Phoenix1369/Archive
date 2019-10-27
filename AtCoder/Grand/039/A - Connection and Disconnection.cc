#include <cstdio>
#include <cstring>
#include <vector>
typedef long long lld;
const int MAXS = 105;
std::vector<int> C;
char S[MAXS];
int K, N;

int cnt, sum;

void push() {
    C.push_back(cnt);
    sum += cnt / 2;
    cnt = 0;
}

void count() {
    cnt = 1;
    sum = 0;
    for (int i = 1; i < N; ++i) {
        if (S[i] != S[i-1]) {
            push();
        }
        ++cnt;
    }
    push();
}

lld solve() {
    count();
    if (C.size() == 1u) {
        return 1LL * K * N / 2;
    }
    if (S[0] != S[N-1]) {
        return 1LL * K * sum;
    }
    int f = C.front();
    int b = C.back();
    int join = (f + b) / 2 - f / 2 - b / 2;
    return 1LL * K * sum + 1LL * (K - 1) * join;
}

int main() {
    scanf(" %s", S);
    scanf("%d", &K);
    N = strlen(S);
    printf("%lld\n", solve());
    return 0;
}
