#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int A[MAXN];
int cut[MAXN]{ };
int ans, B, C, lhs, N;

int main()
{
	scanf(" %d%d", &N, &B);
	ans = C = lhs = 0;
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	// 1. The given sequence has odd == even, so a cut with
	//    a valid left segment implies a valid right segment
	// 2. A valid cut will always be valid, regardless of segments
	for(int i = 1; i < N; ++i)
	{
		lhs += (A[i] & 1);
		if(lhs*2 == i)
			cut[C++] = std::abs(A[i+1]-A[i]);
	}
	std::sort(cut, cut+C);
	for(int i = 0; i < C; ++i)
		if(cut[i] <= B)
		{
			B -= cut[i];
			++ans;
		}
		else
			break;
	printf("%d\n", ans);
	return 0;
}