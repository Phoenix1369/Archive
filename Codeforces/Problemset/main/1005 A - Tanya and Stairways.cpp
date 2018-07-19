#include <cstdio>
const int MAXN = 1005;
int out[MAXN]{ };
int a, m=0, n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		if(i && (a == 1)) ++m;
		out[m] = a;
	}
	printf("%d\n", ++m);
	for(int i = 0; i < m; ++i)
		printf("%d ", out[i]);
    return 0;
}