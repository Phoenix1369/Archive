#include <cstdio>
#define M(x) ((x) % MOD)
const int MAXN = 1E6+5;
const int MOD = 1E9+7;
int F[MAXN], S[MAXN]{ };
int K, N, ret;

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

/* procedure count_perms(x)
 * returns the number of valid permutations of length `x` with `x` last
 * case #1 indexof(x-1) < x-k: (x-k-1) * (x-2)!
 *	freely place `x-1`, shuffle the remaining `x-2` elements
 * case #2 otherwise: all elements up to `x-1` must form a valid permutation
 *      we choose `i-1` elements to permute validly, freely shuffle remaining `x-i-1`
 *	= sum[i: x-k, x-1] count_perms(i) * (x-2 choose i-1) * (x-i-1)!
 *	= (x-2)! * sum[i: x-k, x-1] count_perms(i) / (i-1)!
 * count_perms(x) = (x-2)! * ((x-k-1) + sum[i: x-k, x-1] count_perms(i) / (i-1)!)
 * http://codeforces.com/blog/entry/55734
 */
int count_perms(int x)
{
	if(K >= x) return 0;
	return M(1LL * F[x-2] * M((x-K-1) + M(S[x-1] - S[x-K-1] + MOD)));
}

/* our answer is the sum of all valid permutation considering `n` at each index
 * we choose `i-1` elements to permute validly and freely shuffle remaining `n-i`
 *	ret = sum[i: 1, n] count_perms(i) * (n-1 choose i-1) * (n-i)!
 *          = sum[i: 1, n] count_perms(i) * (n-1)! / (i-1)!
 */
int main()
{
	scanf(" %d%d", &N, &K);
	F[0] = 1;
	for(int i = 1; i <= N; ++i)
		F[i] = 1LL * F[i-1] * i % MOD;
	S[0] = ret = 0;
	for(int i = 1; i <= N; ++i)
	{
		int P = count_perms(i);
		int inv_fac = mMI(F[i-1]);
		ret = M(M(M(1LL * P * inv_fac) * F[N-1]) + ret);
		S[i] =  M(M(1LL * P * inv_fac) + S[i-1]);
	}
	printf("%d\n", ret);
	return 0;
}
