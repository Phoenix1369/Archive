#include <cstdio>
const int MAXN = 10;
int N;

bool solve() {
    for (int i = 1; i < MAXN; ++i) {
        if ((N % i) != 0) {
            continue;
        }
        if (N / i < MAXN) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &N);
    puts(solve() ? "Yes" : "No");
    return 0;
}
