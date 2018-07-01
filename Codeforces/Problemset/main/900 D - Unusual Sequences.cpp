#include <cmath>
#include <cstdio>
#include <unordered_map>
const int MOD = 1E9+7;
std::unordered_map<int,int> cache;
int X, Y;

int fpm(int b, int e)
{
	int p = 1;
	while(e)
	{
		if(e & 1)
			p = 1LL*b*p % MOD;
		b = 1LL*b*b % MOD;
		e >>= 1;
	}
	return p;
}

/* procedure dfs(sum)
 * by stars and bars, there are 2^(sum-1) sequences summing to `sum`
 * exclude sequences for which the gcd of its elements > 1 recursively
 */
int dfs(int sum)
{
	if(cache.count(sum))
		return cache.at(sum);
	int res = fpm(2, sum-1), ss = sqrt(sum);
	for(int i = 2; i <= ss; ++i) if((sum % i) == 0)
		res = ((res - dfs(i) + MOD) % MOD - dfs(sum / i) + MOD) % MOD;
	if(ss*ss == sum) // Square Root counted twice
		res = (res + dfs(ss)) % MOD;
	return cache[sum] = (res - dfs(1) + MOD) % MOD;
}

int main()
{
	scanf(" %d%d", &X, &Y);
	cache.reserve(sqrt(Y/X));
	cache[1] = 1;
	if(Y % X)
		puts("0");
	else
		printf("%d\n", dfs(Y/X));
	return 0;
}