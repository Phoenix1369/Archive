#include <cstdio>
const int MAXN = 10;
bool seq[MAXN]{ };
int x[MAXN];
int m, n, y;

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d", &y);
		seq[y] = true;
	}
	for(int i = 0; i < n; ++i)
		if(seq[x[i]]) printf("%d ", x[i]);
	putchar('\n');
    return 0;
}
