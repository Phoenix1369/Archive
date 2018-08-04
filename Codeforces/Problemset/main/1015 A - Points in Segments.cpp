#include <cstdio>
const int MAXN = 105;
bool pts[MAXN]{ };
int m, n;

int main()
{
	scanf(" %d%d", &n, &m);
	int k = m;
	for(int i = 0; i < n; ++i)
	{
		int l, r;
		scanf(" %d%d", &l, &r);
		for(int j = l; j <= r; ++j) if(!pts[j])
		{
			pts[j] = true;
			--k;
		}
	}
	printf("%d\n", k);
	for(int i = 1; i <= m; ++i)
		if(!pts[i]) printf("%d ", i);
	putchar('\n');
	return 0;
}
