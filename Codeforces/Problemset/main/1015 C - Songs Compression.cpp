#include <algorithm>
#include <cstdio>
#include <utility>
typedef std::pair<int,int> pii;
const int MAXN = 1e5+5;
int a[MAXN], b[MAXN];
int m, n;

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf(" %d%d", &a[i], &b[i]);
	int sum = 0;
	for(int i = 0; i < n; ++i)
		if((sum += b[i]) > m)
			return puts("-1"), 0;
	for(int i = 0; i < n; ++i)
		a[i] -= b[i];
	std::sort(a, a+n);
	int ret = 0;
	for(int i = 0; i < n; ++i)
		if((sum += a[i]) > m)
			return printf("%d\n", n-i) & 0;
	puts("0");
	return 0;
}
