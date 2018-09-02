#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
int a[MAXN]{ };
lld ret=0LL;
int n, s;

int main()
{
    scanf(" %d%d", &n, &s);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    std::sort(a, a+n);
    int m = n>>1;
    for(int i = m; (i < n) && (a[i] < s); ++i)
        ret += s-a[i];
    for(int i = m; (i >= 0) && (a[i] > s); --i)
        ret += a[i]-s;
    printf("%lld\n", ret);
    return 0;
}

