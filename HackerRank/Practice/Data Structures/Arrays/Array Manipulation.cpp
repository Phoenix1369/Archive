#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1E7+5;
lld diff[MAXN]{ };
lld max, sum;
int N, Q;

int main()
{
    scanf(" %d%d", &N, &Q);
    for(int _ = 1; _ <= Q; ++_)
    {
        int a, b, k;
        scanf(" %d%d%d", &a, &b, &k);
        diff[a] += k;
        diff[b+1] -= k;
    }
    for(int i = 1; i <= N; ++i)
    {
        sum += diff[i];
        max = std::max(sum, max);
    }
    printf("%lld\n", max);
    return 0;
}
