#include <cstdio>
#include <set>
typedef long long lld;
std::set<lld> best;
lld a, m;
int n, Q;

int main()
{
    scanf("%d", &Q);
    for(int q = 0; q < Q; ++q)
    {
        scanf(" %d%lld", &n, &m);
        best.clear();
        best.insert(m);
        lld p=0, ret=0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a);
            p = (a % m + p) % m;
            ret = std::max(((p-*best.upper_bound(p)) % m + m) % m, ret);
            best.insert(p);
        }
        printf("%lld\n", ret);
    }
    return 0;
}
