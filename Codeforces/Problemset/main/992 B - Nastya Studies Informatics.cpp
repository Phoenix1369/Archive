#include <cmath>
#include <cstdio>
typedef long long lld;
int l, r, x, y;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int solve()
{
	if((y % x) != 0)
		return 0;
	int k = y / x;
	int s = sqrt(k);
	int ret = 0;
	for(int i = s; 1LL*i*x >= l; --i) if((k % i) == 0)
	{
		int d = k / i;
		if(1LL*d*x > r) break;
		if(gcd(d, i) > 1) continue;
		if(d == i)
			++ret;
		else
			ret += 2;
	}
	return ret;
}

int main()
{
	scanf(" %d%d%d%d", &l, &r, &x, &y);
	printf("%d\n", solve());
	return 0;
}
