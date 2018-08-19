#include <cstdio>
typedef long long lld;
const int MOD = 1e9+7;
lld k;

template <typename T> int rem(T x) { return x % MOD; }
int add(int a, int b) { return rem(a+b); }
int sub(int a, int b) { return add(rem(a-b), MOD); }
int mul(int a, int b) { return rem(1LL*a*b); }

int pow(int b, lld p)
{
	int r = 1;
	while(p)
	{
		if(p & 1)
			r = mul(b, r);
		b = mul(b, b);
		p >>= 1;
	}
	return r;
}

int solve(int x)
{
	x = mul(x, 2);
	if(!k) return x;
	return add(mul(sub(x, 1), pow(2, k)), 1);
}

int main()
{
	lld x;
	scanf(" %lld%lld", &x, &k);
	if(!x)
		puts("0");
	else
		printf("%d\n", solve(rem(x)));
	return 0;
}
