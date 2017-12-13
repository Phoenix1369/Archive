#include <cstdio>
#include <cstring>
#define M(x) ((x) % MOD)
#define MMS(x, y) memset((x), (y), sizeof(x))
const int MAXA = 26;
const int MAXC = 1E6+5;
const int MOD = 1E9+7;
char	A[MAXC], B[MAXC];
int   cnt[MAXA]{ };
int F[MAXC], L;

int mMI(int n)
{	// Modular Multiplicative Inverse
	int a=0, b=1, c, m=MOD, q;
	while(m && n)
	{
		c = b;
		b = a - b * (m / n);
		a = c;
		q = n;
		n = m % n;
		m = q;
	}
	if(a < 0) a += MOD;
	return a;
}

int dfs(int pos, int den, int ret, const char * S)
{	// Digit DP
	if(pos >= L) return ret;

	for(int c = 0; c < S[pos]-'a'; c++) if(cnt[c])
		ret = M(M(M(1LL * F[L-pos-1] * den) * cnt[c]) + ret);

	if(!cnt[S[pos]-'a']) return ret;

	int ned = 1LL * den * cnt[S[pos]-'a']-- % MOD;
	return dfs(pos+1, ned, ret, S);
}

int f(const char * S)
{	// Permutations of `A` < `S`
	MMS(cnt, 0);
	for(int i = 0; i < L; ++i)
		++cnt[A[i]-'a'];
	int D = 1;
	for(int i = 0; i < MAXA; ++i)
		D = 1LL * F[cnt[i]] * D % MOD;
	return dfs(0, mMI(D), 0, S);
}

int main()
{
	scanf(" %s%s", A, B);
	L = strlen(A);
	F[0] = 1;
	for(int i = 1; i <= L; ++i)
		F[i] = 1LL * F[i-1] * i % MOD;
	printf("%d\n", M(M(f(B)-f(A))+MOD-1));
	return 0;
}