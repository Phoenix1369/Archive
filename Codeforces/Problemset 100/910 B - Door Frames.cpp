#include <algorithm>
#include <cstdio>
const int TA=4, TB=2;
int A, B, M=6, N, nda;

int main()
{
	scanf("%d%d%d", &N, &A, &B); nda = N/A;
	for(int i = 1; (i <= TB) && (B*i <= N); ++i)
	{
		int b = i^3;		// Bars used for `B`
		int t = (N-B*i) / A;	// Space left for `A`
		int a = TA - b*t;	// Cut remaining `A`
		M = std::min(b + (a+nda-1) / nda, M);
	}
	printf("%d\n", M);
	return 0;
}