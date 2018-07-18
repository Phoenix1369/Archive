#include <cstdio>
const int MAXN = 1005;
int a[MAXN], c[MAXN];
int bill, game, m, n;

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	for(int i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	bill = game = 0;
	while((game < n) && (bill < m))
	{
		if(c[game] <= a[bill])
			++bill;
		++game;
	}
	printf("%d\n", bill);
    return 0;
}