#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
int	A[MAXN]{ };
int C, L[2], M, N, P, pos;

int main()
{
	scanf("%d%d%d", &N, &M, &C);
	L[0] = 1; L[1] = N+1;
	while(L[0] < L[1])
	{
		scanf("%d", &P);
		if(P <= C>>1)
		{
			pos = std::upper_bound(A+1, A+L[0], P)-A;
			if(pos == L[0]) ++L[0];
		}
		else
		{
			pos = std::lower_bound(A+L[1], A+N+1, P)-A;
			if(--pos < L[1]) --L[1];
		}
		A[pos] = P;
		printf("%d\n", pos);
		fflush(stdout);
	}
	return 0;
}