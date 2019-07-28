#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
typedef long long lld;
const int MAXN = 1e5+5;
int A[MAXN];
std::map<int,lld> cnt;

int main() {
    int M, N;
    scanf(" %d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    std::sort(A, A + N);
    for (int i = 0; i < M; ++i) {
        int B, C;
        scanf(" %d%d", &B, &C);
        cnt[C] += B;
    }
    int j = 0;
    while (!cnt.empty()) {
        auto itr = cnt.rbegin();
        int val = itr->first;
        int k = itr->second;
        for (int i = 0; (i < k) && (j < N); ++i, ++j) {
            if (A[j] >= val) {
                j = N;
                break;
            }
            A[j] = val;
        }
        if (j >= N) break;
        cnt.erase(val);
    }
    lld ret = std::accumulate(A, A + N, 0LL);
    printf("%lld\n", ret);
    return 0;
}
