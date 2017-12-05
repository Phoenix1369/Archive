#include <cmath>
#include <cstdio>
#include <set>
typedef long long lld;
std::set<lld> candid;
lld N, Nsqrt, S;

lld f(lld b, lld n)
{	// TC: O(logN)
	if((b > n) || (b==1))
		return n;
	return f(b, n/b) + (n % b);
}
// Only Two Digits (B > sqrt(N)):
// p*B + q = N   p + q = S
int main()
{
	scanf(" %lld%lld", &N, &S);
	if(S >  N)
		return puts("-1"), 0;
	if(S == N)
		return printf("%lld\n", N+1) & 0;
	Nsqrt = sqrt(N);
	for(int B = 2; B <= Nsqrt; ++B)
		if(f(B, N) == S) candid.insert(B);
	for(lld P = 1; (P*P < N) && (P <= S); ++P)
	{
		lld Q = S - P;
		if((N >= Q) && !((N-Q) % P))
		{
			lld B =  (N-Q) / P;
			if((B > P) && (B > Q))
				candid.insert(B);
		}	// Base must be > Digits!
	}
	if(!candid.empty())
		printf("%lld\n", *candid.begin());
	else
		puts("-1");
	return 0;
}