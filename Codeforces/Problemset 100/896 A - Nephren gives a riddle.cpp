#include <cstdio>
typedef long long lld;
const char * f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const char * fi = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
const char NOPE = '.';
const int L[4] = { 75, 34, 66, 68 };
const int MAXN = 54;
lld	A[MAXN]{ };
int N, Q;
lld K;

char dfs(int n, lld k)
{
	if(!n)	return (k < L[0]) ? f0[k] : NOPE;
	if(k < L[1])
		return fi[k];
	if((n >= MAXN) || (k < L[1]+A[n-1]))
		return dfs(n-1, k-L[1]);
	if(k < A[n-1]+L[2])
		return fi[k-A[n-1]];
	if(k < A[n-1]*2+L[2])
		return dfs(n-1, k-(A[n-1]+L[2]));
	if(k < L[3]+A[n-1]*2)
		return fi[k-A[n-1]*2];
	return NOPE;
}

int main()
{
	A[0] = L[0];
	for(int i = 1; i < MAXN; ++i)
		A[i] = L[3] + 2*A[i-1];
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		scanf(" %d%lld", &N, &K);
		putchar(dfs(N, K-1));
	}
	putchar('\n');
	return 0;
}