#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
int a[MAXN]{ }, n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	a[n++] = 0;
	std::sort(a, a+n);
	printf("%d\n", std::unique(a, a+n)-a-1);
	return 0;
}
