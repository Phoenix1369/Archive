#include <algorithm>
#include <cstdio>
typedef long long lld;
const lld INFL = 1E18;
const int MAXB = 30;
const int MAXN = 2E5+5;
int	A[MAXN]{ };
int N;

/* procedure merge(L1, R1, L2, R2, B)
 * merges the two partitions of vertices by computing the minimum XOR of two sets
 * greedily tries to pair up the quarters with same b-th bit (both ON/OFF)
 * http://codeforces.com/blog/entry/55701?#comment-395075
 */
lld merge(int L1, int R1, int L2, int R2, int B)
{
	if((L1 > R1) || (L2 > R2)) return INFL;
	if(!B) return 0;
	int b = B-1, M1 = R1, M2 = R2;
	while((M1 >= L1) && ((A[M1] >> b) & 1)) --M1;
	while((M2 >= L2) && ((A[M2] >> b) & 1)) --M2;
	if(((L1 <= M1) && (L2 <= M2)) || ((M1 < R1) && (M2 < R2)))
		return std::min(merge(L1, M1, L2, M2, B-1), merge(M1+1, R1, M2+1, R2, B-1));
	else
		return std::min(merge(L1, M1, M2+1, R2, B-1), merge(M1+1, R1, L2, M2, B-1)) + (1<<b);
}

/* procedure split(L, R, bit)
 * recursively splits vertices by the current bit, examining from high to low
 * edges formed internally in these partitions XOR out their MSBs, hence optimal
 * connect the two sub-MST with an edge which must use the B-th bit
 */
lld split(int L, int R, int B)
{
	if((B < 0) || (R-L+1 < 2)) return 0;
	int M = R; lld ret = 0;
	while((M >= L) && ((A[M] >> B) & 1)) --M;
	if((L <= M) && (M < R))
		ret = merge(L, M, M+1, R, B) + (1<<B);
	return split(L, M, B-1) + split(M+1, R, B-1) + ret;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	std::sort(A+1, A+N+1);
	printf("%lld\n", split(1, N, MAXB-1));
	return 0;
}
