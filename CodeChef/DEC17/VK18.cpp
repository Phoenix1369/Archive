#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1E6+5;
lld  dsum[MAXN]{ };
lld  psum[MAXN<<1]{ };
int N, T;

int abs_diff(int M)
{	// Extract Digit Sum
	int sum[2]{ };
	while(M)
	{
		int rem = M % 10;
		sum[rem & 1] += rem;
		M /= 10;
	}
	return std::abs(sum[0] - sum[1]);
}

void init()
{	// Precompute Solutions
	dsum[1] = psum[2] = 2;
	for(int i = 2; i < MAXN; ++i)
	{
		int two = abs_diff(i*2);
		psum[i*2-1] = psum[(i-1)*2] + abs_diff(i*2-1);
		dsum[i] = 2*(psum[i*2-1] - psum[i]) + two + dsum[i-1];
		psum[i*2] = psum[i*2-1] + two;
	}
}

int main()
{
	init();
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf("%d", &N);
		printf("%lld\n", dsum[N]);
	}
	return 0;
}