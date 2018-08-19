#include <cstdio>
const int MAXN = 105;
int a[MAXN], b[MAXN];
int m, n, xum=0;

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		xum ^= a[i];
	}
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d", &b[i]);
		xum ^= b[i];
	}
	puts(xum ? "NO" : "YES");
	if(xum) return 0;
	for(int i = 1; i < n; ++i)
	{
		for(int j = 1; j < m; ++j)
			printf("0 ");
		printf("%d\n", a[i]);
		b[m] ^= a[i];
	}
	for(int j = 1; j < m; ++j)
	{
		printf("%d ", b[j]);
		a[n] ^= b[j];
	}
	printf("%d\n", a[n]);
	return 0;
}
