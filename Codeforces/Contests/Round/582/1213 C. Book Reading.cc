#include <cstdio>
#include <vector>
typedef long long lld;
const int BASE = 10;
bool seen[BASE]{ };
std::vector<int> res;
lld M, N;
int Q;

void init() {
    res.clear();
    for (int i = 0; i < BASE; ++i) {
        seen[i] = false;
    }
}

void residues() {
    int R = M % BASE;
    int cur = R;
    while (!seen[cur]) {
        res.push_back(cur);
        seen[cur] = true;
        cur = (1LL * cur + R) % BASE;
    }
}

lld solve() {
    init();
    residues();

    int S = res.size();
    for (int i = 1; i < S; ++i) {
        res[i] += res[i-1];
    }

    lld K = N / M;
    lld ret = 1LL * res.back() * (K / S);

    int rem = (K % S);
    if (rem) ret += 1LL * res[rem - 1];
    return ret;
}

int main() {
    scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
        scanf(" %lld%lld", &N, &M);
        printf("%lld\n", solve());
    }
    return 0;
}
