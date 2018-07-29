#include <cstdio>
const int MAXK = 1e5;
bool rem[MAXK];
int a, g, k, n, ret;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main()
{
	scanf(" %d%d", &n, &k);
	g = ret = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		g = gcd(a%k, g);
	}
	for(int i = 0; i < k; ++i)
	{
		int d = 1LL*g*i % k;
		if(rem[d]) continue;
		rem[d] = true;
		++ret;
	}
	printf("%d\n", ret);
	for(int i = 0; i < k; ++i)
		if(rem[i]) printf("%d ", i);
	putchar('\n');
	return 0;
}
