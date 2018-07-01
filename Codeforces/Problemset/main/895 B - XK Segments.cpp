#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1E5+5;
lld	A[MAXN]{ };
int K, N, X;
lld ret=0LL;

int main()
{
	scanf(" %d%d%d", &N, &X, &K);
	for(int i = 0; i < N; ++i)
		scanf("%lld", &A[i]);
	std::sort(A, A+N);
	for(int i = 0; i < N; ++i)
	{
		lld high = ((A[i] + 1LL*K*X + X-1) / X) * X;
		lld lowe = high-X;
		if(!K && !(A[i] % X)) continue;
		if(!K) ++lowe;
		lowe = std::max(A[i], lowe); // a_i <= a_j
		auto L = std::lower_bound(A, A+N, lowe);
		auto R = std::lower_bound(A, A+N, high);
		ret += R - L;
	}
	printf("%lld\n", ret);
	return 0;
}
