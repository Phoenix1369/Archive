#include <cstdio>
const int MAXN = 1E6+5;
const int MOD = 998244353;
int a[MAXN], c[MAXN];
int n, two, sum;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	c[1] = two = sum = 1;
	for(int i = 2; i <= n; ++i)
	{
		two = 2LL * two % MOD;
		c[i] = (1LL * i * two % MOD - sum + MOD) % MOD;
		sum = (1LL * c[i] + sum) % MOD;
	}
	int ret = 0;
	for(int i = 1; i <= n; ++i)
		ret = (1LL * a[i] * c[n-i+1] % MOD + ret) % MOD;
	printf("%d\n", ret);
    return 0;
}