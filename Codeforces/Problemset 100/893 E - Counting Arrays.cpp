#include <cstdio>
#define MMI(n) dfs_mmi(0, 1, MOD, (n))
const int MAXX = 1E6+20;
const int MOD  = 1E9+7;
int F[MAXX], G[MAXX], S[MAXX]{ };
int Q;

int dfs_mmi(int a, int b, int m, int n)
{	// Modular Multiplicative Inverse
	return (m && n) ? dfs_mmi(b, a - b * (m / n), n, m % n) : (a < 0) ? (a + MOD) : a;
}

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

void init()
{
	F[0] = G[0] = 1;
	for(int i = 1; i < MAXX; ++i)
	{
		F[i] = 1LL*F[i-1]*i % MOD;
		G[i] = MMI(F[i]);
	}
	S[0] = S[1] = 1;
	for(int i = 2; i < MAXX; ++i) if(!S[i])
	{	// Smallest Prime Divisor
		S[i] = i;
		if(1LL*i*i >= MAXX) continue;
		for(int j = i*i; j < MAXX; j += i)
			if(!S[j]) S[j] = i;
	}
}

int nCr(int n, int r) { return 1LL * F[n] * G[r] % MOD * G[n-r] % MOD; }

int main()
{
	init();
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		int ans=1, cnt=0, x, y;
		scanf(" %d%d", &x, &y);
		while(x > 1)
		{
			++cnt;
			int w = x / S[x];
			if(S[w] != S[x])
			{
				ans = 1LL*ans*nCr(cnt+y-1,cnt) % MOD;
				cnt = 0;
			}
			x = w;
		}
		ans = 1LL*ans*fpm(2,y-1) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}