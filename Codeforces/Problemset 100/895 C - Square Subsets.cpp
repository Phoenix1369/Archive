#include <cstdio>
const int MAXA = 71;
const int MAXK = 11; // pi(MAXA/2)
const int MAXP = 1<<MAXK;
const int MOD  = 1E9+7;
int    dp[MAXA][MAXP]{ };
int	S[MAXA]{ };
int cnt[MAXA], eve[MAXA], mask[MAXA], odd[MAXA], prime[MAXA];
int N, num, P=0;

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
	return	p;
}

void init()
{
	for(int i = 0; i < MAXA; ++i)
		cnt[i] = mask[i] = odd[i] = 0;
	for(int i = 0; i < MAXA; ++i)
		eve[i] = 1;
	S[0] = S[1] = 1;
	for(int i = 2; i < MAXA; ++i) if(!S[i])
	{
		mask[i] = (1<<P);
		prime[P++] = i;
		for(int j = i; j < MAXA; j += i)
			S[j] = i;
	}
	else
		mask[i] = mask[i/S[i]] ^ mask[S[i]];
}

int main()
{
	init();
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		++cnt[num];
	}
	for(int i = 0; i < MAXA; ++i) if(cnt[i])
		eve[i] = odd[i] = fpm(2, cnt[i]-1);
	dp[0][0] = 1;
	for(int i = 1; i < MAXA; ++i)
	for(int j = 0; j < MAXP; ++j)
		if((mask[i] >> MAXK) == 0)
		{
			dp[i][j] = (1LL*dp[i-1][j]*eve[i] % MOD + dp[i][j]) % MOD;
			dp[i][j^mask[i]] = (1LL*dp[i-1][j]*odd[i] % MOD + dp[i][j^mask[i]]) % MOD;
		}
		else	// Skip Large Primes - Only divides self
			dp[i][j] = dp[i-1][j];
	int ret = dp[MAXA-1][0];
	for(int i = 0; i < P; ++i)
		if(prime[i] > MAXA/2)
			ret = 1LL*ret*eve[prime[i]] % MOD;
	printf("%d\n", (ret - 1 + MOD) % MOD);	// Exclude Empty Set
	return 0;
}